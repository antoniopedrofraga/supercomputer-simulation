#include "system.h"

System::System(Configuration * config) {
    this->config = config;
    this->statistics = new Statistics(config);
    this->total_cores_nr = config->get_cores_nr() * config->get_nodes_nr();
    create_users();
    create_jobs();
    schedule();
    calculate_op_cost();
}

System::System(Configuration * config, vector<User*> users, vector<Job> jobs) {
    this->config = config;
    if (config->get_jobs_nr() != jobs.size()) {
        throw std::invalid_argument("Jobs number does not match vector size.\n");
    }
    this->statistics = new Statistics(config);
    this->total_cores_nr = config->get_cores_nr() * config->get_nodes_nr();
    this->users = users;
    this->jobs = jobs;
    for (int i = 0; i < jobs.size(); i++) {
        int user_id = 0;
        while (!users[user_id]->can_afford(&jobs[i])) {
            user_id++;
        }
        statistics->add_usage_price(jobs[i].get_price());
        users[user_id]->pay(&jobs[i]);
        jobs[i].set_user(users[user_id]);
    }
    schedule();
    calculate_op_cost();
}

bool System::exist_negatives() {
    for (int i = 0; i < states.size(); i++) {
        if (states[i].get_short_cores() < 0 ||
            states[i].get_medium_cores() < 0 ||
            states[i].get_large_cores() < 0) {
            return true;
    }
}
return false;
}

void System::create_users() {
    int user_nr = config->get_jobs_nr();
    for (int i = 0; i < user_nr; i++) {
        users.push_back(new User(config, i, false));
    }
    users.push_back(new User(config, user_nr, true));
}

void System::create_jobs() {
    int nr_users = users.size();
    int nr_jobs = config->get_jobs_nr();
    unsigned long long int now = config->get_time();

    random_device rd;
    exponential_distribution<double> rng(6);
    mt19937 rnd_gen(rd());

    for (int i = 0; i < nr_jobs; i++) {
        unsigned long long int rand_seconds = config->get_requests_span() * rng(rnd_gen), duration = THIRTY_EIGHT_HOURS * rng(rnd_gen);
        time_t time = (time_t)(now + rand_seconds);
        int user_id = 0;
        Job * job = new Job(config, time, duration);
        while (!users[user_id]->can_afford(job)) {
            user_id++;
        }
        statistics->add_usage_price(job->get_price());
        users[user_id]->pay(job);
        job->set_user(users[user_id]);

        jobs.push_back(*job);
    }
    sort(jobs.begin(), jobs.end());
}

void System::insert_state_at_the_end(time_t start, time_t end, Job job) {
    statistics->add_job(start, job);

    State * start_state = new State(this->total_cores_nr, start, Start, job.get_name());
    start_state->insert_job(job);
    State * end_state = new State(this->total_cores_nr, end, End, job.get_name());
    states.push_back(*start_state);
    states.push_back(*end_state);
}

void System::insert_state_and_update(int i, int j, time_t start, time_t end, Job job) {
    statistics->add_job(start, job);

    State * start_state = i - 1 >= 0 ? new State(states[i - 1], start, Start, job.get_name()) : new State(this->total_cores_nr, start, Start, job.get_name());
    start_state->insert_job(job);
    State * end_state = !job.is_huge() && j - 1 >= 0 ? new State(states[j - 1], end, End, job.get_name()) : new State(this->total_cores_nr, end, End, job.get_name());
    for (int k = i; k < j; k++) {
        states[k].insert_job(job);
    }
    states.insert(states.begin() + j, *end_state);
    states.insert(states.begin() + i, *start_state);
}


void System::insert_week_state(time_t start, int i, Job job) {
    time_t end = start + job.get_duration();
    while (i - 1 >= 0 && i - 1 < states.size() && !states[i - 1].can_insert_job(job)) {
        i++;
        start = states[i - 1].get_time();
        end = start + job.get_duration();
        if (is_weekend(start, end)) {
            start = advance_weekend(start);
            end = start + job.get_duration();
            while (i < states.size() &&  states[i].get_time() <= start) {
                i++;
            }
        }
    }
    int j = i;
    while (i - 1 >= 0 && j < states.size() && states[j].get_time() <= end) {
        if (!states[j].can_insert_job(job)) {
            i = j + 1;
            start = states[i - 1].get_time();
            end = start + job.get_duration();
            while (i - 1 < states.size() && !states[i - 1].can_insert_job(job)) {
                i++;
                start = states[i - 1].get_time();
                end = start + job.get_duration();
                if (is_weekend(start, end)) {
                    start = advance_weekend(start);
                    end = start + job.get_duration();
                    while (i < states.size() &&  states[i].get_time() <= start) {
                        i++;
                    }
                }
            }
            j = i;
        } else {
            j++;
        }
    }
    insert_state_and_update(i, j, start, end, job);
}

void System::insert_weekend_state(time_t s, int index, Job job) {
    time_t start = advance_to_friday(s), end;
    int i = index;
    while (i < states.size() && states[i].get_time() < start) {
        i++;
    }
    while (i < states.size() && states[i].get_time() == start) {
        start = advance_to_friday(start);
        while (i < states.size() && states[i].get_time() < start) {
            i++;
        }
    }
    end = start + job.get_duration();
    if (i < states.size()) {
        insert_state_and_update(i, i, start, end, job);
    } else {
        insert_state_at_the_end(start, end, job);
    }
}

void System::insert_state(int &index, Job job) {
    time_t start = job.get_time();
    while (index < states.size() && states[index].get_time() <= start) {
        index++;
    }
    if (!job.is_huge()) {
        insert_week_state(start, index, job);
    } else {
        insert_weekend_state(start, index, job);
    }
} 

void System::schedule() {
    int index = 0;
    for (int i = 0; i < jobs.size(); i++) {
        insert_state(index, jobs[i]);
    }
}

void System::calculate_op_cost() {
    int level = 0;
    time_t start = 0;
    for (int i = 0; i < states.size(); i++) {
        if (states[i].get_type() == Start) {
            if (level == 0) {
                start = states[i].get_time();
            }
            level++;
        } else {
            level--;
            if (level == 0) {
                statistics->add_machine_time(states[i].get_time() - start);
            }
        }
    }
    if (states.size() >= 2) {
        statistics->add_operational_cost((states[states.size() - 1].get_time() - states[0].get_time()) * config->get_operational_cost());
    }
}

string System::get_results() {
    stringstream results;
    results << "Is sorted: " << (std::is_sorted(states.begin(),states.end()) ? "true" : "false") << endl << endl;
    results << "Exist negatives: " << (exist_negatives() ? "true" : "false") << endl << endl;
    results << "Machine time consumed by jobs: " << statistics->get_machine_time() << endl << endl;
    results << "Price paid by users: £" << statistics->get_usage_price() << endl << endl;
    results << "Operational Cost: £" << statistics->get_operational_cost() << endl << endl;
    results << "Economic Balance: £" << statistics->get_economic_balance() << endl << endl;
    results << "Average waiting time (seconds):" << " Short(" << statistics->get_short_wt() << "), Medium(" << statistics->get_medium_wt() << "), Large(" << statistics->get_large_wt() << "), Huge(" << statistics->get_huge_wt() << ")" << endl << endl;
    results << "Average turnaround ratio:" << " Short(" << statistics->get_short_ta() << "), Medium(" << statistics->get_medium_ta() << "), Large(" << statistics->get_large_ta() << "), Huge(" << statistics->get_huge_ta() << ")" << endl << endl;
    results << endl;
    results << "Queues weekly usage: " << endl << statistics->get_weekly_usage() << endl;
    return results.str();
}
