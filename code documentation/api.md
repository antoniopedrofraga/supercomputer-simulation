# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`enum `[`Type`](#type_8h_1a1d1cfd8ffb84e947f82999c682b666a7)            | [Job](#classJob) type enum.
`enum `[`StateType`](#statetype_8h_1a1615968a92950438f6e67a28e9d56e5c)            | StateType enum.
`enum `[`Group`](#group_8h_1ace1050b29fb6a0619ecf018e6cb26bce)            | Group enum.
`public bool `[`operator<`](#job_8cpp_1a7cd0c5ec425cbac29dc2d35c316736a8)`(`[`Job`](#classJob)` const & a,`[`Job`](#classJob)` const & b)`            | < Operator overload.
`public ostream & `[`operator<<`](#week_8cpp_1a5c17f115d399c08f1b848e8d8ce05e3f)`(ostream & os,const `[`Week`](#classWeek)` & week)`            | Converts the week object to a specific ostream output format.
`public bool `[`operator<`](#state_8cpp_1a3d174276607841e38f2c6291a46c1c8f)`(`[`State`](#classState)` const & a,`[`State`](#classState)` const & b)`            | < Operator overload.
`public int `[`generate_random`](#utils_8cpp_1a922ea9938b27158961175da47eacbdcb)`(int low,int high)`            | Public method. Method to generate a random integer value following a linear distribution. This value lies between a lower and upper bound.
`public unsigned int `[`generate_random`](#utils_8cpp_1a005b8a9907ecda6a5d1cc679f359c4eb)`(unsigned int low,unsigned int high)`            | Public method. Method to generate a random unsigned integer value following a linear distribution. This value lies between a lower and upper bound.
`public double `[`generate_random`](#utils_8cpp_1abf4b1e0b40143d203b5f8383e0a22236)`(double low,double high)`            | Public method. Method to generate a random double value following a linear distribution. This value lies between a lower and upper bound.
`public bool `[`is_weekend`](#utils_8cpp_1a154e11312aa498d684ee7ed9d425439a)`(time_t start,time_t end)`            | Public method. Method to check if a job runs through the weekend.
`public bool `[`is_weekend`](#utils_8cpp_1ac3420a318a42603ec9c9d32d4748b98b)`(time_t start)`            | Public method. Method to check if a job starts in a weekend.
`public time_t `[`advance_weekend`](#utils_8cpp_1a2a95cd9f87463141a0996904e313a46a)`(time_t start)`            | Public method. Advances a given time until Monday at 9:00.
`public time_t `[`advance_to_friday`](#utils_8cpp_1acb74aab2b1555fecd2bd0956b352dcd6)`(time_t start)`            | Public method. Advances a given time until Friday at 17:00.
`public time_t `[`get_back_to_monday`](#utils_8cpp_1a7aab7e0568d3e2b2fdee79807d1010c6)`(time_t start)`            | Public method. Returns a given time to Monday at 9:00.
`public int `[`generate_random`](#utils_8h_1a922ea9938b27158961175da47eacbdcb)`(int low,int high)`            | Public method. Method to generate a random integer value following a linear distribution. This value lies between a lower and upper bound.
`public unsigned int `[`generate_random`](#utils_8h_1a005b8a9907ecda6a5d1cc679f359c4eb)`(unsigned int low,unsigned int high)`            | Public method. Method to generate a random unsigned integer value following a linear distribution. This value lies between a lower and upper bound.
`public double `[`generate_random`](#utils_8h_1abf4b1e0b40143d203b5f8383e0a22236)`(double low,double high)`            | Public method. Method to generate a random double value following a linear distribution. This value lies between a lower and upper bound.
`public bool `[`is_weekend`](#utils_8h_1a154e11312aa498d684ee7ed9d425439a)`(time_t start,time_t end)`            | Public method. Method to check if a job runs through the weekend.
`public bool `[`is_weekend`](#utils_8h_1ac3420a318a42603ec9c9d32d4748b98b)`(time_t start)`            | Public method. Method to check if a job starts in a weekend.
`public time_t `[`advance_weekend`](#utils_8h_1a2a95cd9f87463141a0996904e313a46a)`(time_t start)`            | Public method. Advances a given time until Monday at 9:00.
`public time_t `[`advance_to_friday`](#utils_8h_1acb74aab2b1555fecd2bd0956b352dcd6)`(time_t start)`            | Public method. Advances a given time until Friday at 17:00.
`public time_t `[`get_back_to_monday`](#utils_8h_1a7aab7e0568d3e2b2fdee79807d1010c6)`(time_t start)`            | Public method. Returns a given time to Monday at 9:00.
`class `[`Configuration`](#classConfiguration) | [Configuration](#classConfiguration) class.
`class `[`Job`](#classJob) | [Job](#classJob) class.
`class `[`MainWindow`](#classMainWindow) | [MainWindow](#classMainWindow) class.
`class `[`State`](#classState) | [State](#classState) class.
`class `[`Statistics`](#classStatistics) | [Statistics](#classStatistics) class.
`class `[`System`](#classSystem) | [System](#classSystem) class.
`class `[`User`](#classUser) | [System](#classSystem) class.
`class `[`Week`](#classWeek) | [Week](#classWeek) class.

## Members

#### `enum `[`Type`](#type_8h_1a1d1cfd8ffb84e947f82999c682b666a7) {#type_8h_1a1d1cfd8ffb84e947f82999c682b666a7}

[Job](#classJob) type enum.

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
Short            | 
Medium            | 
Large            | 
Huge            | 

Enum. Defining whether a job is Short, Medium, Large or Huge.

#### `enum `[`StateType`](#statetype_8h_1a1615968a92950438f6e67a28e9d56e5c) {#statetype_8h_1a1615968a92950438f6e67a28e9d56e5c}

StateType enum.

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
Start            | 
End            | 

Enum. Defining whether a state represents a starting or ending of a job.

#### `enum `[`Group`](#group_8h_1ace1050b29fb6a0619ecf018e6cb26bce) {#group_8h_1ace1050b29fb6a0619ecf018e6cb26bce}

Group enum.

 Values                         | Descriptions                                
--------------------------------|---------------------------------------------
ITsupport            | 
Researcher            | 
Student            | 

Enum. Defining the groups that an [User](#classUser) can be part of.

#### `public bool `[`operator<`](#job_8cpp_1a7cd0c5ec425cbac29dc2d35c316736a8)`(`[`Job`](#classJob)` const & a,`[`Job`](#classJob)` const & b)` {#job_8cpp_1a7cd0c5ec425cbac29dc2d35c316736a8}

< Operator overload.

#### `public ostream & `[`operator<<`](#week_8cpp_1a5c17f115d399c08f1b848e8d8ce05e3f)`(ostream & os,const `[`Week`](#classWeek)` & week)` {#week_8cpp_1a5c17f115d399c08f1b848e8d8ce05e3f}

Converts the week object to a specific ostream output format.

#### `public bool `[`operator<`](#state_8cpp_1a3d174276607841e38f2c6291a46c1c8f)`(`[`State`](#classState)` const & a,`[`State`](#classState)` const & b)` {#state_8cpp_1a3d174276607841e38f2c6291a46c1c8f}

< Operator overload.

#### `public int `[`generate_random`](#utils_8cpp_1a922ea9938b27158961175da47eacbdcb)`(int low,int high)` {#utils_8cpp_1a922ea9938b27158961175da47eacbdcb}

Public method. Method to generate a random integer value following a linear distribution. This value lies between a lower and upper bound.

Public const unsigned long long. Default requests time span upper bound. The configuration value is initialized with this value.

#### Parameters
* `int` low. Lower bound. 

* `int` high. Upper bound. 

#### Returns
int. Randomly generated integer value. 

**See also**: unsigned int generate_random(unsigned int low, unsigned int high) 

**See also**: double generate_random(double low, double high)

#### `public unsigned int `[`generate_random`](#utils_8cpp_1a005b8a9907ecda6a5d1cc679f359c4eb)`(unsigned int low,unsigned int high)` {#utils_8cpp_1a005b8a9907ecda6a5d1cc679f359c4eb}

Public method. Method to generate a random unsigned integer value following a linear distribution. This value lies between a lower and upper bound.

#### Parameters
* `unsigned` int low. Lower bound. 

* `unsigned` int high. Upper bound. 

#### Returns
unsigned int. Randomly generated unsigned integer value. 

**See also**: int generate_random(int low, int high) 

**See also**: double generate_random(double low, double high)

#### `public double `[`generate_random`](#utils_8cpp_1abf4b1e0b40143d203b5f8383e0a22236)`(double low,double high)` {#utils_8cpp_1abf4b1e0b40143d203b5f8383e0a22236}

Public method. Method to generate a random double value following a linear distribution. This value lies between a lower and upper bound.

#### Parameters
* `double` low. Lower bound. 

* `double` high. Upper bound. 

#### Returns
double. Randomly generated double value. 

**See also**: int generate_random(int low, int high) 

**See also**: unsigned int generate_random(unsigned int low, unsigned int high)

#### `public bool `[`is_weekend`](#utils_8cpp_1a154e11312aa498d684ee7ed9d425439a)`(time_t start,time_t end)` {#utils_8cpp_1a154e11312aa498d684ee7ed9d425439a}

Public method. Method to check if a job runs through the weekend.

#### Parameters
* `time_t` start. Starting time of a job. 

* `time_t` end. Ending time of a job. 

#### Returns
bool. True if it does, false if doesn't. 

**See also**: bool is_weekend(time_t start)

#### `public bool `[`is_weekend`](#utils_8cpp_1ac3420a318a42603ec9c9d32d4748b98b)`(time_t start)` {#utils_8cpp_1ac3420a318a42603ec9c9d32d4748b98b}

Public method. Method to check if a job starts in a weekend.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
bool. True if it does, false if doesn't. 

**See also**: bool is_weekend(time_t start, time_t end)

#### `public time_t `[`advance_weekend`](#utils_8cpp_1a2a95cd9f87463141a0996904e313a46a)`(time_t start)` {#utils_8cpp_1a2a95cd9f87463141a0996904e313a46a}

Public method. Advances a given time until Monday at 9:00.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
time_t. Next Monday at 9:00 in UNIX timestamp.

#### `public time_t `[`advance_to_friday`](#utils_8cpp_1acb74aab2b1555fecd2bd0956b352dcd6)`(time_t start)` {#utils_8cpp_1acb74aab2b1555fecd2bd0956b352dcd6}

Public method. Advances a given time until Friday at 17:00.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
time_t. Next Friday at 17:00 in UNIX timestamp.

#### `public time_t `[`get_back_to_monday`](#utils_8cpp_1a7aab7e0568d3e2b2fdee79807d1010c6)`(time_t start)` {#utils_8cpp_1a7aab7e0568d3e2b2fdee79807d1010c6}

Public method. Returns a given time to Monday at 9:00.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
time_t. Previous Monday at 9:00 in UNIX timestamp.

#### `public int `[`generate_random`](#utils_8h_1a922ea9938b27158961175da47eacbdcb)`(int low,int high)` {#utils_8h_1a922ea9938b27158961175da47eacbdcb}

Public method. Method to generate a random integer value following a linear distribution. This value lies between a lower and upper bound.

Public const unsigned long long. Default requests time span upper bound. The configuration value is initialized with this value.

#### Parameters
* `int` low. Lower bound. 

* `int` high. Upper bound. 

#### Returns
int. Randomly generated integer value. 

**See also**: unsigned int generate_random(unsigned int low, unsigned int high) 

**See also**: double generate_random(double low, double high)

#### `public unsigned int `[`generate_random`](#utils_8h_1a005b8a9907ecda6a5d1cc679f359c4eb)`(unsigned int low,unsigned int high)` {#utils_8h_1a005b8a9907ecda6a5d1cc679f359c4eb}

Public method. Method to generate a random unsigned integer value following a linear distribution. This value lies between a lower and upper bound.

#### Parameters
* `unsigned` int low. Lower bound. 

* `unsigned` int high. Upper bound. 

#### Returns
unsigned int. Randomly generated unsigned integer value. 

**See also**: int generate_random(int low, int high) 

**See also**: double generate_random(double low, double high)

#### `public double `[`generate_random`](#utils_8h_1abf4b1e0b40143d203b5f8383e0a22236)`(double low,double high)` {#utils_8h_1abf4b1e0b40143d203b5f8383e0a22236}

Public method. Method to generate a random double value following a linear distribution. This value lies between a lower and upper bound.

#### Parameters
* `double` low. Lower bound. 

* `double` high. Upper bound. 

#### Returns
double. Randomly generated double value. 

**See also**: int generate_random(int low, int high) 

**See also**: unsigned int generate_random(unsigned int low, unsigned int high)

#### `public bool `[`is_weekend`](#utils_8h_1a154e11312aa498d684ee7ed9d425439a)`(time_t start,time_t end)` {#utils_8h_1a154e11312aa498d684ee7ed9d425439a}

Public method. Method to check if a job runs through the weekend.

#### Parameters
* `time_t` start. Starting time of a job. 

* `time_t` end. Ending time of a job. 

#### Returns
bool. True if it does, false if doesn't. 

**See also**: bool is_weekend(time_t start)

#### `public bool `[`is_weekend`](#utils_8h_1ac3420a318a42603ec9c9d32d4748b98b)`(time_t start)` {#utils_8h_1ac3420a318a42603ec9c9d32d4748b98b}

Public method. Method to check if a job starts in a weekend.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
bool. True if it does, false if doesn't. 

**See also**: bool is_weekend(time_t start, time_t end)

#### `public time_t `[`advance_weekend`](#utils_8h_1a2a95cd9f87463141a0996904e313a46a)`(time_t start)` {#utils_8h_1a2a95cd9f87463141a0996904e313a46a}

Public method. Advances a given time until Monday at 9:00.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
time_t. Next Monday at 9:00 in UNIX timestamp.

#### `public time_t `[`advance_to_friday`](#utils_8h_1acb74aab2b1555fecd2bd0956b352dcd6)`(time_t start)` {#utils_8h_1acb74aab2b1555fecd2bd0956b352dcd6}

Public method. Advances a given time until Friday at 17:00.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
time_t. Next Friday at 17:00 in UNIX timestamp.

#### `public time_t `[`get_back_to_monday`](#utils_8h_1a7aab7e0568d3e2b2fdee79807d1010c6)`(time_t start)` {#utils_8h_1a7aab7e0568d3e2b2fdee79807d1010c6}

Public method. Returns a given time to Monday at 9:00.

#### Parameters
* `time_t` start. Starting time of a job. 

#### Returns
time_t. Previous Monday at 9:00 in UNIX timestamp.

# class `Configuration` {#classConfiguration}

[Configuration](#classConfiguration) class.

This object includes the input values of the simulation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Configuration`](#classConfiguration_1a779947337bf652f0e773cb29f37f14ba)`()` | [Configuration](#classConfiguration) object default contructor.
`public unsigned int `[`get_users_nr`](#classConfiguration_1ace5f9aa5555419110b7df4e6eb664931)`()` | Public method. Returns the number of users when this value is not generated randomly.
`public unsigned int `[`get_users_nr_min`](#classConfiguration_1a09999edf2be5ece81d64ea825c7fd339)`()` | Public method. Returns the lower limit of randomly generated values of number of users.
`public unsigned int `[`get_users_nr_max`](#classConfiguration_1a2ce1f2af9f9733712a8cbbfb7f5b277c)`()` | Public method. Returns the upper limit of randomly generated values of number of users.
`public bool `[`is_users_nr_random`](#classConfiguration_1a3c6d60da873c53d2a785e64f67668c4f)`()` | Public method. Returns true if the number of users is generated randomly, and false if it's not.
`public unsigned int `[`get_jobs_nr`](#classConfiguration_1a09d80d794d6614c7bcbdf12b49835f02)`()` | Public method. Returns the number of jobs when this value is not generated randomly.
`public unsigned int `[`get_jobs_nr_min`](#classConfiguration_1a3d224269091e27f9595485ec5d4b0467)`()` | Public method. Returns the lower limit of randomly generated values of number of jobs.
`public unsigned int `[`get_jobs_nr_max`](#classConfiguration_1a19e2080f751736cf98017f6e40533629)`()` | Public method. Returns the upper limit of randomly generated values of number of jobs.
`public bool `[`is_jobs_nr_random`](#classConfiguration_1ae35b4429de406ed81c1be1ae54bfc3d7)`()` | Public method. Returns true if the number of jobs is generated randomly, and false if it's not.
`public unsigned int `[`get_cores_nr`](#classConfiguration_1a3255f4b61deb08b21a39251b9dc4d2b4)`()` | Public method. Returns the number of cores per node.
`public unsigned int `[`get_nodes_nr`](#classConfiguration_1aafbd7647fdc9447cf882083a0be02263)`()` | Public method. Returns the total number of system nodes.
`public double `[`get_usage_price`](#classConfiguration_1a65edb47ed369c917d275812bba3e46c8)`()` | Public method. Returns the usage price of the system per core second.
`public double `[`get_operational_cost`](#classConfiguration_1a3a3d1dd3bb8ef78b09fbed9954ec1c8f)`()` | Public method. Returns the operational cost of the system per second.
`public double `[`get_student_budget`](#classConfiguration_1af7b5ce431f51f8848e32ba76af63c531)`()` | Public method. Returns the student budget.
`public double `[`get_student_budget_min`](#classConfiguration_1a3a6291edf176db0bdcc4b88c529a6447)`()` | Public method. Returns the lower limit of randomly generated values of student budget.
`public double `[`get_student_budget_max`](#classConfiguration_1a9b8da18d74cdedc6d779c560d714fbc1)`()` | Public method. Returns the upper limit of randomly generated values of student budget.
`public bool `[`is_student_budget_random`](#classConfiguration_1ac5422f301431649bfc63319bf4b0b2e9)`()` | Public method. Returns true if the student budget is generated randomly, and false if it's not.
`public double `[`get_researcher_budget`](#classConfiguration_1a9555ca72e72aacb78585365a328c3c9f)`()` | Public method. Returns the researcher budget.
`public double `[`get_researcher_budget_min`](#classConfiguration_1aefb667cc98649f5a32fc16665c6b28c9)`()` | Public method. Returns the lower limit of randomly generated values of researcher budget.
`public double `[`get_researcher_budget_max`](#classConfiguration_1ac4ae307e11f10c5cf1a0e32d14621948)`()` | Public method. Returns the upper limit of randomly generated values of researcher budget.
`public bool `[`is_researcher_budget_random`](#classConfiguration_1aaf2bcbe58e2a4844c2f6d74a94191ac5)`()` | Public method. Returns true if the researcher budget is generated randomly, and false if it's not.
`public time_t `[`get_time`](#classConfiguration_1aeb49a69a8a52a9603d5e46180a73b770)`()` | Public method. Returns the starting time of the simulation in UNIX timestamp format.
`public unsigned long long int `[`get_requests_span`](#classConfiguration_1a4f94d71b89f3fdea573050da6fe5e0e6)`()` | Public method. Returns the requests time span in seconds.
`public void `[`set_student_random`](#classConfiguration_1a057a8d808d077731c582ec280a897bf9)`(bool random)` | Public method. Changes the way the student budget is defined.
`public void `[`set_researcher_random`](#classConfiguration_1a6230496122b25f645092fe3b9896f883)`(bool random)` | Public method. Changes the way the researcher budget is defined.
`public void `[`set_users_random`](#classConfiguration_1aedf812b154b8cc8b3db322f6d969ca59)`(bool random)` | Public method. Changes the way the number of users is defined.
`public void `[`set_jobs_random`](#classConfiguration_1acd24051b1759e61132d6653e0df9dfe4)`(bool random)` | Public method. Changes the way the number of jobs is defined.
`public void `[`set_now`](#classConfiguration_1a1d5547d2f203074882e1d6d3c5ddbb8a)`(bool now)` | Public method. Changes whether the simulation starting time is the present date or not.
`public void `[`set_time`](#classConfiguration_1a7d9e089372333b0c1ec93c7fdbd297f2)`(time_t time)` | Public method. Defines a date value for non-present starting dates simulations.
`public void `[`set_usage_price`](#classConfiguration_1a0b9459ad48edbac60dcd8962910653a2)`(double usage_price)` | Public method. Defines the usage price of the system per core second.
`public void `[`set_operational_cost`](#classConfiguration_1a31284f3adcd959a1092a27efb5742452)`(double operational_cost)` | Public method. Defines the operational cost of the system per core second.
`public void `[`set_nodes_nr`](#classConfiguration_1ac74a221224fbf7db75c3afa47fba2d61)`(unsigned int nodes_nr)` | Public method. Defines the total number of system nodes.
`public void `[`set_cores_nr`](#classConfiguration_1a299244e0d054564921a3344b14e94973)`(unsigned int cores_nr)` | Public method. Defines the number of cores per node.
`public void `[`set_student_budget`](#classConfiguration_1a00fb5adcb5145810133ef68a662dca91)`(double budget)` | Public method. Defines the student budget of a new simulation.
`public void `[`set_student_budget_min`](#classConfiguration_1ae6cc1bfec9271811e94df8a6bba264f0)`(double min)` | Public method. Defines the lower limit student budgets when this value is randomly generated.
`public void `[`set_student_budget_max`](#classConfiguration_1aba1e5f9fe84879c3628382096015cd94)`(double max)` | Public method. Defines the upper limit student budgets when this value is randomly generated.
`public void `[`set_researcher_budget`](#classConfiguration_1a92a48764d5717464989aed435de76bc6)`(double budget)` | Public method. Defines the researcher budget of a new simulation.
`public void `[`set_researcher_budget_min`](#classConfiguration_1a8fb6a2c896ca9a98ffa605b84b6ddde7)`(double min)` | Public method. Defines the lower limit researcher budgets when this value is randomly generated.
`public void `[`set_researcher_budget_max`](#classConfiguration_1add79fec297e6e38097b3a0b9968c8d2c)`(double max)` | Public method. Defines the upper limit researcher budgets when this value is randomly generated.
`public void `[`set_jobs_nr`](#classConfiguration_1a915a2e408d2c2b95e0e7cfe4a5842c2d)`(unsigned int nr)` | Public method. Defines the number of jobs of a new simulation.
`public void `[`set_jobs_nr_min`](#classConfiguration_1a5132f41c23a73bb4fded422f325cbbe6)`(unsigned int min)` | Public method. Defines the lower limit of jobs when this value is randomly generated.
`public void `[`set_jobs_nr_max`](#classConfiguration_1a288259d1e0c47f99ddd0feec5ade6d93)`(unsigned int max)` | Public method. Defines the upper limit of jobs when this value is randomly generated.
`public void `[`set_users_nr`](#classConfiguration_1a0e27b300afd52eb1a07f202ee8a05746)`(unsigned int nr)` | Public method. Defines the number of users of a new simulation.
`public void `[`set_users_nr_min`](#classConfiguration_1aca5c8d3046cc871ce78b0c6ef0d3cda6)`(unsigned int min)` | Public method. Defines the lower limit of users when this value is randomly generated.
`public void `[`set_users_nr_max`](#classConfiguration_1af5b4e0360ab5bc2d5535e993850e2f23)`(unsigned int max)` | Public method. Defines the upper limit of users when this value is randomly generated.
`public void `[`set_requests_span`](#classConfiguration_1a485b378ed96796fd7a7ca17ace180060)`(unsigned long long int span)` | Public method. Defines the requests time span.

## Members

#### `public  `[`Configuration`](#classConfiguration_1a779947337bf652f0e773cb29f37f14ba)`()` {#classConfiguration_1a779947337bf652f0e773cb29f37f14ba}

[Configuration](#classConfiguration) object default contructor.

Private time_t. Start time of the simulation.

Initializes a [Configuration](#classConfiguration) object.

Default contructor of configuration. The default input values are defined in the "utils.h" header file.

#### `public unsigned int `[`get_users_nr`](#classConfiguration_1ace5f9aa5555419110b7df4e6eb664931)`()` {#classConfiguration_1ace5f9aa5555419110b7df4e6eb664931}

Public method. Returns the number of users when this value is not generated randomly.

#### Returns
unsigned int. The number of users.

Ŕeturns a constant value if the variable "users_random" is false, and a random value between two established limits if not.

#### `public unsigned int `[`get_users_nr_min`](#classConfiguration_1a09999edf2be5ece81d64ea825c7fd339)`()` {#classConfiguration_1a09999edf2be5ece81d64ea825c7fd339}

Public method. Returns the lower limit of randomly generated values of number of users.

#### Returns
unsigned int. The lower limit.

Ŕeturns the lower limit of randomly generated values of users numbers.

#### `public unsigned int `[`get_users_nr_max`](#classConfiguration_1a2ce1f2af9f9733712a8cbbfb7f5b277c)`()` {#classConfiguration_1a2ce1f2af9f9733712a8cbbfb7f5b277c}

Public method. Returns the upper limit of randomly generated values of number of users.

#### Returns
unsigned int. The upper limit.

Ŕeturns the upper limit of randomly generated values of users numbers.

#### `public bool `[`is_users_nr_random`](#classConfiguration_1a3c6d60da873c53d2a785e64f67668c4f)`()` {#classConfiguration_1a3c6d60da873c53d2a785e64f67668c4f}

Public method. Returns true if the number of users is generated randomly, and false if it's not.

#### Returns
bool. Number of users randomness.

Ŕeturns whether the number of users is randomly generated or not.

#### `public unsigned int `[`get_jobs_nr`](#classConfiguration_1a09d80d794d6614c7bcbdf12b49835f02)`()` {#classConfiguration_1a09d80d794d6614c7bcbdf12b49835f02}

Public method. Returns the number of jobs when this value is not generated randomly.

#### Returns
unsigned int. The number of jobs.

Ŕeturns a constant value if the variable "jobs_random" is false, and a random value between two established limits if not.

#### `public unsigned int `[`get_jobs_nr_min`](#classConfiguration_1a3d224269091e27f9595485ec5d4b0467)`()` {#classConfiguration_1a3d224269091e27f9595485ec5d4b0467}

Public method. Returns the lower limit of randomly generated values of number of jobs.

#### Returns
unsigned int. The lower limit.

Ŕeturns the lower limit of randomly generated values of jobs numbers.

#### `public unsigned int `[`get_jobs_nr_max`](#classConfiguration_1a19e2080f751736cf98017f6e40533629)`()` {#classConfiguration_1a19e2080f751736cf98017f6e40533629}

Public method. Returns the upper limit of randomly generated values of number of jobs.

#### Returns
unsigned int. The upper limit.

Ŕeturns the upper limit of randomly generated values of jobs numbers.

#### `public bool `[`is_jobs_nr_random`](#classConfiguration_1ae35b4429de406ed81c1be1ae54bfc3d7)`()` {#classConfiguration_1ae35b4429de406ed81c1be1ae54bfc3d7}

Public method. Returns true if the number of jobs is generated randomly, and false if it's not.

#### Returns
bool. Number of jobs randomness.

Ŕeturns whether the number of jobs is randomly generated or not.

#### `public unsigned int `[`get_cores_nr`](#classConfiguration_1a3255f4b61deb08b21a39251b9dc4d2b4)`()` {#classConfiguration_1a3255f4b61deb08b21a39251b9dc4d2b4}

Public method. Returns the number of cores per node.

#### Returns
unsigned int. The number of cores per node.

Ŕeturns the number of cores per node.

#### `public unsigned int `[`get_nodes_nr`](#classConfiguration_1aafbd7647fdc9447cf882083a0be02263)`()` {#classConfiguration_1aafbd7647fdc9447cf882083a0be02263}

Public method. Returns the total number of system nodes.

#### Returns
unsigned int. The number of nodes.

Ŕeturns the total number of nodes.

#### `public double `[`get_usage_price`](#classConfiguration_1a65edb47ed369c917d275812bba3e46c8)`()` {#classConfiguration_1a65edb47ed369c917d275812bba3e46c8}

Public method. Returns the usage price of the system per core second.

#### Returns
double. Usage price of the system per core second.

Ŕeturns the usage price of the system per core second.

#### `public double `[`get_operational_cost`](#classConfiguration_1a3a3d1dd3bb8ef78b09fbed9954ec1c8f)`()` {#classConfiguration_1a3a3d1dd3bb8ef78b09fbed9954ec1c8f}

Public method. Returns the operational cost of the system per second.

#### Returns
double. Operational cost of the system per second.

Ŕeturns the operational cost of the system per second.

#### `public double `[`get_student_budget`](#classConfiguration_1af7b5ce431f51f8848e32ba76af63c531)`()` {#classConfiguration_1af7b5ce431f51f8848e32ba76af63c531}

Public method. Returns the student budget.

#### Returns
double. Student budget value.

Ŕeturns a constant value if the variable "student_random" is false, and a random value between two established limits if not.

#### `public double `[`get_student_budget_min`](#classConfiguration_1a3a6291edf176db0bdcc4b88c529a6447)`()` {#classConfiguration_1a3a6291edf176db0bdcc4b88c529a6447}

Public method. Returns the lower limit of randomly generated values of student budget.

#### Returns
double. The lower limit of student budget.

Ŕeturns the lower limit of a randomly generated student budget.

#### `public double `[`get_student_budget_max`](#classConfiguration_1a9b8da18d74cdedc6d779c560d714fbc1)`()` {#classConfiguration_1a9b8da18d74cdedc6d779c560d714fbc1}

Public method. Returns the upper limit of randomly generated values of student budget.

#### Returns
double. The upper limit of student budget.

Ŕeturns the upper limit of a randomly generated student budget.

#### `public bool `[`is_student_budget_random`](#classConfiguration_1ac5422f301431649bfc63319bf4b0b2e9)`()` {#classConfiguration_1ac5422f301431649bfc63319bf4b0b2e9}

Public method. Returns true if the student budget is generated randomly, and false if it's not.

#### Returns
bool. Student budget randomness.

Ŕeturns whether the student budget is randomly generated or not.

#### `public double `[`get_researcher_budget`](#classConfiguration_1a9555ca72e72aacb78585365a328c3c9f)`()` {#classConfiguration_1a9555ca72e72aacb78585365a328c3c9f}

Public method. Returns the researcher budget.

#### Returns
double. Student budget value.

Ŕeturns a constant value if the variable "student_random" is false, and a random value between two established limits if not.

#### `public double `[`get_researcher_budget_min`](#classConfiguration_1aefb667cc98649f5a32fc16665c6b28c9)`()` {#classConfiguration_1aefb667cc98649f5a32fc16665c6b28c9}

Public method. Returns the lower limit of randomly generated values of researcher budget.

#### Returns
double. The lower limit of researcher budget.

Ŕeturns the lower limit of a randomly generated researcher budget.

#### `public double `[`get_researcher_budget_max`](#classConfiguration_1ac4ae307e11f10c5cf1a0e32d14621948)`()` {#classConfiguration_1ac4ae307e11f10c5cf1a0e32d14621948}

Public method. Returns the upper limit of randomly generated values of researcher budget.

#### Returns
double. The upper limit of researcher budget.

Ŕeturns the upper limit of a randomly generated researcher budget.

#### `public bool `[`is_researcher_budget_random`](#classConfiguration_1aaf2bcbe58e2a4844c2f6d74a94191ac5)`()` {#classConfiguration_1aaf2bcbe58e2a4844c2f6d74a94191ac5}

Public method. Returns true if the researcher budget is generated randomly, and false if it's not.

#### Returns
bool. Researcher budget randomness.

Ŕeturns whether the researcher budget is randomly generated or not.

#### `public time_t `[`get_time`](#classConfiguration_1aeb49a69a8a52a9603d5e46180a73b770)`()` {#classConfiguration_1aeb49a69a8a52a9603d5e46180a73b770}

Public method. Returns the starting time of the simulation in UNIX timestamp format.

#### Returns
time_t. Starting time of the simulation.

Returns the simulation starting date, the current UNIX time stamp if the "now" is true, a defined date if it's false.

#### `public unsigned long long int `[`get_requests_span`](#classConfiguration_1a4f94d71b89f3fdea573050da6fe5e0e6)`()` {#classConfiguration_1a4f94d71b89f3fdea573050da6fe5e0e6}

Public method. Returns the requests time span in seconds.

#### Returns
time_t. Requests time span.

Ŕeturns the requests time span in seconds.

#### `public void `[`set_student_random`](#classConfiguration_1a057a8d808d077731c582ec280a897bf9)`(bool random)` {#classConfiguration_1a057a8d808d077731c582ec280a897bf9}

Public method. Changes the way the student budget is defined.

#### Parameters
* `bool` random. True if random generated, false if constant.

Defines whether the student budget is randomly generated or not.

#### `public void `[`set_researcher_random`](#classConfiguration_1a6230496122b25f645092fe3b9896f883)`(bool random)` {#classConfiguration_1a6230496122b25f645092fe3b9896f883}

Public method. Changes the way the researcher budget is defined.

#### Parameters
* `bool` random. True if random generated, false if constant.

Defines whether the researcher budget is randomly generated or not.

#### `public void `[`set_users_random`](#classConfiguration_1aedf812b154b8cc8b3db322f6d969ca59)`(bool random)` {#classConfiguration_1aedf812b154b8cc8b3db322f6d969ca59}

Public method. Changes the way the number of users is defined.

#### Parameters
* `bool` random. True if random generated, false if constant.

Defines whether the number of users is randomly generated or not.

#### `public void `[`set_jobs_random`](#classConfiguration_1acd24051b1759e61132d6653e0df9dfe4)`(bool random)` {#classConfiguration_1acd24051b1759e61132d6653e0df9dfe4}

Public method. Changes the way the number of jobs is defined.

#### Parameters
* `bool` random. True if random generated, false if constant.

Defines whether the number of jobs is randomly generated or not.

#### `public void `[`set_now`](#classConfiguration_1a1d5547d2f203074882e1d6d3c5ddbb8a)`(bool now)` {#classConfiguration_1a1d5547d2f203074882e1d6d3c5ddbb8a}

Public method. Changes whether the simulation starting time is the present date or not.

#### Parameters
* `bool` now. True if the date is the present, false if not.

Defines whether the simulation starting date is the present or not.

#### `public void `[`set_time`](#classConfiguration_1a7d9e089372333b0c1ec93c7fdbd297f2)`(time_t time)` {#classConfiguration_1a7d9e089372333b0c1ec93c7fdbd297f2}

Public method. Defines a date value for non-present starting dates simulations.

#### Parameters
* `time_t` time. Value of date in UNIX timestamp format.

Defines the simulation starting date.

#### `public void `[`set_usage_price`](#classConfiguration_1a0b9459ad48edbac60dcd8962910653a2)`(double usage_price)` {#classConfiguration_1a0b9459ad48edbac60dcd8962910653a2}

Public method. Defines the usage price of the system per core second.

#### Parameters
* `double` usage_price. New value of usage price.

Defines the value of the usage price of the system.

#### `public void `[`set_operational_cost`](#classConfiguration_1a31284f3adcd959a1092a27efb5742452)`(double operational_cost)` {#classConfiguration_1a31284f3adcd959a1092a27efb5742452}

Public method. Defines the operational cost of the system per core second.

#### Parameters
* `double` usage_price. New value of operational cost.

Defines the value of the operational cost of the system.

#### `public void `[`set_nodes_nr`](#classConfiguration_1ac74a221224fbf7db75c3afa47fba2d61)`(unsigned int nodes_nr)` {#classConfiguration_1ac74a221224fbf7db75c3afa47fba2d61}

Public method. Defines the total number of system nodes.

#### Parameters
* `unsigned` int nodes_nr. New value of total number of system nodes.

Defines number of nodes of the system.

#### `public void `[`set_cores_nr`](#classConfiguration_1a299244e0d054564921a3344b14e94973)`(unsigned int cores_nr)` {#classConfiguration_1a299244e0d054564921a3344b14e94973}

Public method. Defines the number of cores per node.

#### Parameters
* `unsigned` int nodes_nr. New value of number of cores per node.

Defines number of cores per node.

#### `public void `[`set_student_budget`](#classConfiguration_1a00fb5adcb5145810133ef68a662dca91)`(double budget)` {#classConfiguration_1a00fb5adcb5145810133ef68a662dca91}

Public method. Defines the student budget of a new simulation.

#### Parameters
* `double` budget. New value of student budget.

Defines value of a student budget.

#### `public void `[`set_student_budget_min`](#classConfiguration_1ae6cc1bfec9271811e94df8a6bba264f0)`(double min)` {#classConfiguration_1ae6cc1bfec9271811e94df8a6bba264f0}

Public method. Defines the lower limit student budgets when this value is randomly generated.

#### Parameters
* `double` min. New value of lower limit.

Defines the lower limit of randomly generated student budgets, never letting this value being higher than the upper limit.

#### `public void `[`set_student_budget_max`](#classConfiguration_1aba1e5f9fe84879c3628382096015cd94)`(double max)` {#classConfiguration_1aba1e5f9fe84879c3628382096015cd94}

Public method. Defines the upper limit student budgets when this value is randomly generated.

#### Parameters
* `double` max. New value of upper limit.

Defines the upper limit of randomly generated student budgets, never letting this value being smaller than the upper limit.

#### `public void `[`set_researcher_budget`](#classConfiguration_1a92a48764d5717464989aed435de76bc6)`(double budget)` {#classConfiguration_1a92a48764d5717464989aed435de76bc6}

Public method. Defines the researcher budget of a new simulation.

#### Parameters
* `double` budget. New value of researcher budget.

Defines value of a researcher budget.

#### `public void `[`set_researcher_budget_min`](#classConfiguration_1a8fb6a2c896ca9a98ffa605b84b6ddde7)`(double min)` {#classConfiguration_1a8fb6a2c896ca9a98ffa605b84b6ddde7}

Public method. Defines the lower limit researcher budgets when this value is randomly generated.

#### Parameters
* `double` min. New value of lower limit.

Defines the lower limit of randomly generated researcher budgets, never letting this value being higher than the upper limit.

#### `public void `[`set_researcher_budget_max`](#classConfiguration_1add79fec297e6e38097b3a0b9968c8d2c)`(double max)` {#classConfiguration_1add79fec297e6e38097b3a0b9968c8d2c}

Public method. Defines the upper limit researcher budgets when this value is randomly generated.

#### Parameters
* `double` max. New value of upper limit.

Defines the upper limit of randomly generated researcher budgets, never letting this value being smaller than the upper limit.

#### `public void `[`set_jobs_nr`](#classConfiguration_1a915a2e408d2c2b95e0e7cfe4a5842c2d)`(unsigned int nr)` {#classConfiguration_1a915a2e408d2c2b95e0e7cfe4a5842c2d}

Public method. Defines the number of jobs of a new simulation.

#### Parameters
* `unsigned` int budget. New value of jobs number.

Defines number of jobs.

#### `public void `[`set_jobs_nr_min`](#classConfiguration_1a5132f41c23a73bb4fded422f325cbbe6)`(unsigned int min)` {#classConfiguration_1a5132f41c23a73bb4fded422f325cbbe6}

Public method. Defines the lower limit of jobs when this value is randomly generated.

#### Parameters
* `unsigned` int min. New value of lower limit.

Defines the lower limit of randomly generated number of jobs, never letting this value being higher than the upper limit.

#### `public void `[`set_jobs_nr_max`](#classConfiguration_1a288259d1e0c47f99ddd0feec5ade6d93)`(unsigned int max)` {#classConfiguration_1a288259d1e0c47f99ddd0feec5ade6d93}

Public method. Defines the upper limit of jobs when this value is randomly generated.

#### Parameters
* `unsigned` int max. New value of upper limit.

Defines the upper limit of randomly generated number of jobs, never letting this value being smaller than the upper limit.

#### `public void `[`set_users_nr`](#classConfiguration_1a0e27b300afd52eb1a07f202ee8a05746)`(unsigned int nr)` {#classConfiguration_1a0e27b300afd52eb1a07f202ee8a05746}

Public method. Defines the number of users of a new simulation.

#### Parameters
* `unsigned` int budget. New value of users number.

Defines number of users.

#### `public void `[`set_users_nr_min`](#classConfiguration_1aca5c8d3046cc871ce78b0c6ef0d3cda6)`(unsigned int min)` {#classConfiguration_1aca5c8d3046cc871ce78b0c6ef0d3cda6}

Public method. Defines the lower limit of users when this value is randomly generated.

#### Parameters
* `unsigned` int min. New value of lower limit.

Defines the lower limit of randomly generated number of users, never letting this value being higher than the upper limit.

#### `public void `[`set_users_nr_max`](#classConfiguration_1af5b4e0360ab5bc2d5535e993850e2f23)`(unsigned int max)` {#classConfiguration_1af5b4e0360ab5bc2d5535e993850e2f23}

Public method. Defines the upper limit of users when this value is randomly generated.

#### Parameters
* `unsigned` int max. New value of upper limit.

Defines the upper limit of randomly generated number of users, never letting this value being smaller than the upper limit.

#### `public void `[`set_requests_span`](#classConfiguration_1a485b378ed96796fd7a7ca17ace180060)`(unsigned long long int span)` {#classConfiguration_1a485b378ed96796fd7a7ca17ace180060}

Public method. Defines the requests time span.

#### Parameters
* `unsigned` long long int span. New value of requests time span.

Defines the upper limit of requests time span in seconds.

# class `Job` {#classJob}

[Job](#classJob) class.

This object represents a job submited by an user.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Job`](#classJob_1aa876f2c96653d4b4749359444c653546)`(`[`Configuration`](#classConfiguration)` * config,time_t time,unsigned long long int duration)` | [Job](#classJob) object default contructor.
`public time_t `[`get_time`](#classJob_1a3a9d5b907691c1a5f3e3b7dae9434232)`()` | Public method. Returns the submission time of a job.
`public unsigned long long int `[`get_duration`](#classJob_1ada2d6b6ad399dd2a5d9677770bc31dd2)`()` | Public method. Returns the duration of a job.
`public int `[`get_cores`](#classJob_1a1983414eca65855ad4b60016d8f4732d)`()` | Public method. Returns the number of cores taken to run this job.
`public double `[`get_price`](#classJob_1ae1623b448348b01c5b2216e59789a3bf)`()` | Public method. Returns the price to be paid to run this job.
`public void `[`set_user`](#classJob_1ace0d1b35fda43268e8a80cf846a59b02)`(`[`User`](#classUser)` * user)` | Public method. Defines the user who submits the job.
`public bool `[`is_short`](#classJob_1af82ed715e92ab934401cd31af3582fbd)`()` | Public method. Return whether a job is Short or not.
`public bool `[`is_medium`](#classJob_1a544bd796241d22eb4a2b96d2086f705a)`()` | Public method. Return whether a job is Medium or not.
`public bool `[`is_large`](#classJob_1a7ce2c1d04f42a48f379d43080361fbc8)`()` | Public method. Return whether a job is Large or not.
`public bool `[`is_huge`](#classJob_1ac34a235386a111274a5f55e2534c323b)`()` | Public method. Return whether a job is Huge or not.

## Members

#### `public  `[`Job`](#classJob_1aa876f2c96653d4b4749359444c653546)`(`[`Configuration`](#classConfiguration)` * config,time_t time,unsigned long long int duration)` {#classJob_1aa876f2c96653d4b4749359444c653546}

[Job](#classJob) object default contructor.

Private int. Computational resources taken by this job in cores.

Initializes a [Job](#classJob) object. 
#### Parameters
* `Configuration*` config. Defines which configuration this job should follow. 

* `time_t` time. Submission date of job. 

* `unsigned` long long int duration. [Job](#classJob) duration in seconds.

Contructor of [Job](#classJob) object. Defines what is the type of a job according to its duration, generating its number of cores randomly, following a linear distribution.

#### `public time_t `[`get_time`](#classJob_1a3a9d5b907691c1a5f3e3b7dae9434232)`()` {#classJob_1a3a9d5b907691c1a5f3e3b7dae9434232}

Public method. Returns the submission time of a job.

#### Returns
time_t. Date represented in UNIX timestamp.

Ŕeturns the submission time of a job.

#### `public unsigned long long int `[`get_duration`](#classJob_1ada2d6b6ad399dd2a5d9677770bc31dd2)`()` {#classJob_1ada2d6b6ad399dd2a5d9677770bc31dd2}

Public method. Returns the duration of a job.

#### Returns
unsigned long long int. Duration of job.

Returns the job duration in seconds.

#### `public int `[`get_cores`](#classJob_1a1983414eca65855ad4b60016d8f4732d)`()` {#classJob_1a1983414eca65855ad4b60016d8f4732d}

Public method. Returns the number of cores taken to run this job.

#### Returns
int. Number of cores.

Ŕeturns the number of cores taken by a job.

#### `public double `[`get_price`](#classJob_1ae1623b448348b01c5b2216e59789a3bf)`()` {#classJob_1ae1623b448348b01c5b2216e59789a3bf}

Public method. Returns the price to be paid to run this job.

#### Returns
double. Price to be paid by a simulated user.

Ŕeturns the price to pay to run a job.

#### `public void `[`set_user`](#classJob_1ace0d1b35fda43268e8a80cf846a59b02)`(`[`User`](#classUser)` * user)` {#classJob_1ace0d1b35fda43268e8a80cf846a59b02}

Public method. Defines the user who submits the job.

#### Parameters
* `User*` user. [User](#classUser) who submits the job.

Defines the user who submited the job.

#### `public bool `[`is_short`](#classJob_1af82ed715e92ab934401cd31af3582fbd)`()` {#classJob_1af82ed715e92ab934401cd31af3582fbd}

Public method. Return whether a job is Short or not.

#### Returns
bool. True if yes, false if it's not.

Ŕeturns whether the job is short or not.

#### `public bool `[`is_medium`](#classJob_1a544bd796241d22eb4a2b96d2086f705a)`()` {#classJob_1a544bd796241d22eb4a2b96d2086f705a}

Public method. Return whether a job is Medium or not.

#### Returns
bool. True if yes, false if it's not.

Ŕeturns whether the job is medium or not.

#### `public bool `[`is_large`](#classJob_1a7ce2c1d04f42a48f379d43080361fbc8)`()` {#classJob_1a7ce2c1d04f42a48f379d43080361fbc8}

Public method. Return whether a job is Large or not.

#### Returns
bool. True if yes, false if it's not.

Ŕeturns whether the job is large or not.

#### `public bool `[`is_huge`](#classJob_1ac34a235386a111274a5f55e2534c323b)`()` {#classJob_1ac34a235386a111274a5f55e2534c323b}

Public method. Return whether a job is Huge or not.

#### Returns
bool. True if yes, false if it's not.

Ŕeturns whether the job is huge or not.

# class `MainWindow` {#classMainWindow}

```
class MainWindow
  : public QMainWindow
```  

[MainWindow](#classMainWindow) class.

This object is the GUI.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`MainWindow`](#classMainWindow_1a8b244be8b7b7db1b08de2a2acb9409db)`(QWidget * parent)` | [MainWindow](#classMainWindow) object default contructor.
`public  `[`~MainWindow`](#classMainWindow_1ae98d00a93bc118200eeef9f9bba1dba7)`()` | [MainWindow](#classMainWindow) object default destructor.

## Members

#### `public  explicit `[`MainWindow`](#classMainWindow_1a8b244be8b7b7db1b08de2a2acb9409db)`(QWidget * parent)` {#classMainWindow_1a8b244be8b7b7db1b08de2a2acb9409db}

[MainWindow](#classMainWindow) object default contructor.

Initializes a [MainWindow](#classMainWindow) object.

#### `public  `[`~MainWindow`](#classMainWindow_1ae98d00a93bc118200eeef9f9bba1dba7)`()` {#classMainWindow_1ae98d00a93bc118200eeef9f9bba1dba7}

[MainWindow](#classMainWindow) object default destructor.

Destructs a [MainWindow](#classMainWindow) object.

# class `State` {#classState}

[State](#classState) class.

This object represents a the number of cores available in each queue at every start time and end time of a job.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`State`](#classState_1a08aed9caf1cc4d3be0ba98ec6ce361b6)`(long long int total_cores,time_t time,StateType state_type)` | [State](#classState) object default contructor.
`public  `[`State`](#classState_1a5c1f8c662bc19d86e5b63104b7be9a1c)`(`[`State`](#classState)` state,time_t time,StateType state_type)` | [State](#classState) object alternative contructor.
`public void `[`set_period`](#classState_1a576b0286b5b9bb517b45c29749f5563c)`(time_t start,time_t end)` | Public method. Defines the period of life of a state.
`public void `[`insert_job`](#classState_1a03e0b92997f17eed2272c67cfcdd889a)`(`[`Job`](#classJob)` job)` | Public method. Decreases number of available cores according to job type.
`public bool `[`can_insert_job`](#classState_1a5307764c6bd8793d84b791c47e847635)`(`[`Job`](#classJob)` job)` | Public method. Indicates whether a job can be inserted in this state or not.
`public time_t `[`get_time`](#classState_1a5fa477c55eb40f020372974f84b7a5e6)`()` | Public method. Returns the state time of occurence.
`public string `[`get_name`](#classState_1ae179223944551fda8ffadbde68972a4f)`()` | Public method. Returns the state time of occurence.
`public StateType `[`get_type`](#classState_1a59a20bf57d4ffb9748cbf3b1c051c071)`()` | Public method. Returns type of state.
`public long long int `[`get_short_cores`](#classState_1a29689f616cf6fca4c07b5a7952c324a4)`()` | Public method. Returns available number of cores reserved for short jobs.
`public long long int `[`get_medium_cores`](#classState_1a6f260fbc2e8cf6ffeb9249808e07c525)`()` | Public method. Returns available number of cores reserved for medium jobs.
`public long long int `[`get_large_cores`](#classState_1a97489ea52b70c2a2630ce80655c94d16)`()` | Public method. Returns available number of cores reserved for large jobs.
`public long long int `[`get_total_cores`](#classState_1a3b5789fd6d375e09066b3119f994a536)`()` | Public method. Returns total number of cores.
`public long long int `[`get_used_cores`](#classState_1a3be179b26f26137117e2e303d7b1bbdc)`()` | Public method. Returns total number of used cores.

## Members

#### `public  `[`State`](#classState_1a08aed9caf1cc4d3be0ba98ec6ce361b6)`(long long int total_cores,time_t time,StateType state_type)` {#classState_1a08aed9caf1cc4d3be0ba98ec6ce361b6}

[State](#classState) object default contructor.

Private time_t. Time which this state occurs reprensented in UNIX timestamp.

Initializes a [Job](#classJob) object. 
#### Parameters
* `long` long int total_cores. Total number of system cores. 

* `time_t` time. Date of occurence. 

* `StateType` state_type. StateType indicating whether a job starts or ends.

Default contructor of [State](#classState).

#### `public  `[`State`](#classState_1a5c1f8c662bc19d86e5b63104b7be9a1c)`(`[`State`](#classState)` state,time_t time,StateType state_type)` {#classState_1a5c1f8c662bc19d86e5b63104b7be9a1c}

[State](#classState) object alternative contructor.

Initializes a [Job](#classJob) object. 
#### Parameters
* `[State](#classState)` state. [State](#classState) to copy cat. 

* `time_t` time. Date of occurence. 

* `StateType` state_type. StateType indicating whether a job starts or ends.

Alternative contructor of [State](#classState).

#### `public void `[`set_period`](#classState_1a576b0286b5b9bb517b45c29749f5563c)`(time_t start,time_t end)` {#classState_1a576b0286b5b9bb517b45c29749f5563c}

Public method. Defines the period of life of a state.

#### Parameters
* `time_t` start. Starting time. 

* `time_t` end. Ending time.

#### `public void `[`insert_job`](#classState_1a03e0b92997f17eed2272c67cfcdd889a)`(`[`Job`](#classJob)` job)` {#classState_1a03e0b92997f17eed2272c67cfcdd889a}

Public method. Decreases number of available cores according to job type.

#### Parameters
* `[Job](#classJob)` job. [Job](#classJob) object containing information about what amount of computational resources to be decreased.

Decreases the available number of a computational resources available in the system according to type of job.

#### `public bool `[`can_insert_job`](#classState_1a5307764c6bd8793d84b791c47e847635)`(`[`Job`](#classJob)` job)` {#classState_1a5307764c6bd8793d84b791c47e847635}

Public method. Indicates whether a job can be inserted in this state or not.

#### Parameters
* `[Job](#classJob)` job. [Job](#classJob) object containing information about what amount of computational resources to be decreased. 

#### Returns
bool. True if job can be inserted, false if can not.

Indicates whether a job can run with the available computational resources at this system state.

#### `public time_t `[`get_time`](#classState_1a5fa477c55eb40f020372974f84b7a5e6)`()` {#classState_1a5fa477c55eb40f020372974f84b7a5e6}

Public method. Returns the state time of occurence.

#### Returns
time_t. Date in UNIX timestamp.

Returns time of ocurrence.

#### `public string `[`get_name`](#classState_1ae179223944551fda8ffadbde68972a4f)`()` {#classState_1ae179223944551fda8ffadbde68972a4f}

Public method. Returns the state time of occurence.

#### Returns
time_t. Date in UNIX timestamp.

#### `public StateType `[`get_type`](#classState_1a59a20bf57d4ffb9748cbf3b1c051c071)`()` {#classState_1a59a20bf57d4ffb9748cbf3b1c051c071}

Public method. Returns type of state.

#### Returns
StateType. Start or End.

Returns state type.

#### `public long long int `[`get_short_cores`](#classState_1a29689f616cf6fca4c07b5a7952c324a4)`()` {#classState_1a29689f616cf6fca4c07b5a7952c324a4}

Public method. Returns available number of cores reserved for short jobs.

#### Returns
ong long int. Number of cores.

Returns the amount of available computational resources for short jobs.

#### `public long long int `[`get_medium_cores`](#classState_1a6f260fbc2e8cf6ffeb9249808e07c525)`()` {#classState_1a6f260fbc2e8cf6ffeb9249808e07c525}

Public method. Returns available number of cores reserved for medium jobs.

#### Returns
ong long int. Number of cores.

Returns the amount of available computational resources for medium jobs.

#### `public long long int `[`get_large_cores`](#classState_1a97489ea52b70c2a2630ce80655c94d16)`()` {#classState_1a97489ea52b70c2a2630ce80655c94d16}

Public method. Returns available number of cores reserved for large jobs.

#### Returns
ong long int. Number of cores.

Returns the amount of available computational resources for large jobs.

#### `public long long int `[`get_total_cores`](#classState_1a3b5789fd6d375e09066b3119f994a536)`()` {#classState_1a3b5789fd6d375e09066b3119f994a536}

Public method. Returns total number of cores.

#### Returns
ong long int. Number of cores.

Returns the total number of cores.

#### `public long long int `[`get_used_cores`](#classState_1a3be179b26f26137117e2e303d7b1bbdc)`()` {#classState_1a3be179b26f26137117e2e303d7b1bbdc}

Public method. Returns total number of used cores.

#### Returns
ong long int. Number of cores.

Returns the number of used cores.

# class `Statistics` {#classStatistics}

[Statistics](#classStatistics) class.

This object keeps statistics information structured and organized.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Statistics`](#classStatistics_1abf8cd294ac6cda2aeee639defc276702)`(`[`Configuration`](#classConfiguration)` * config)` | [Statistics](#classStatistics) object default contructor.
`public string `[`get_usage_price`](#classStatistics_1af4c128bde8bed27787f5ecdb08bf9929)`()` | Public method. Returns the total usage price as a string.
`public string `[`get_machine_time`](#classStatistics_1afb354cc8fcd9ab43ec9c3d9e2880e660)`()` | Public method. Returns the total machine time as a string.
`public string `[`get_operational_cost`](#classStatistics_1a091d26462ea4db2b2a6032b94ff49a31)`()` | Public method. Returns the total operational cost as a string.
`public string `[`get_economic_balance`](#classStatistics_1a20e75d62f6802875eec1ebd8424d84b1)`()` | Public method. Returns the economic balance as a string.
`public string `[`get_weekly_usage`](#classStatistics_1a6f5e39adedce4de0c0983619fb8498c8)`()` | Public method. Returns the weekly usage as a string.
`public string `[`get_short_ta`](#classStatistics_1a7858a6d068d7c56d29a5f54c20a8521c)`()` | Public method. Returns the average turn around ratio of short jobs.
`public string `[`get_medium_ta`](#classStatistics_1a114925dbd18467fed3db887104d27807)`()` | Public method. Returns the average turn around ratio of medium jobs.
`public string `[`get_large_ta`](#classStatistics_1a6f0aacba4f01c18cc9da75b1cb2f3e51)`()` | Public method. Returns the average turn around ratio of large jobs.
`public string `[`get_huge_ta`](#classStatistics_1a6afcfec266fe44d1c876be80f09f6de3)`()` | Public method. Returns the average turn around ratio of huge jobs.
`public string `[`get_short_wt`](#classStatistics_1abef59b8f494093e62ff1a27bd989e42a)`()` | Public method. Returns the average waiting time of short jobs.
`public string `[`get_medium_wt`](#classStatistics_1aa20489eecdafe0ebcac554f34b60caef)`()` | Public method. Returns the average waiting time of medium jobs.
`public string `[`get_large_wt`](#classStatistics_1a06c13d01f1a8ea83391628b9bf617a4f)`()` | Public method. Returns the average waiting time of large jobs.
`public string `[`get_huge_wt`](#classStatistics_1a17dc31579326d8463eba7dd661673f47)`()` | Public method. Returns the average waiting time of huge jobs.
`public void `[`add_usage_price`](#classStatistics_1af99eab950e1fa1a657332fface5dc13e)`(double price)` | Public method. Adds price to total usage price.
`public void `[`add_operational_cost`](#classStatistics_1a17bca1fa9938f98e93cebd56d428f9a4)`(double cost)` | Public method. Adds cost to total operational cost.
`public void `[`add_machine_time`](#classStatistics_1a726b0734f8a0c86024543190ab3092ea)`(unsigned long long int time)` | Public method. Adds time to total machine time.
`public void `[`add_job`](#classStatistics_1a78e4c255a4999ebd6c8872eef6360427)`(time_t start,`[`Job`](#classJob)` job)` | Public method. Adds job to waiting time and turn around vectors.

## Members

#### `public  `[`Statistics`](#classStatistics_1abf8cd294ac6cda2aeee639defc276702)`(`[`Configuration`](#classConfiguration)` * config)` {#classStatistics_1abf8cd294ac6cda2aeee639defc276702}

[Statistics](#classStatistics) object default contructor.

Private unsigned long long int. Total machine time of the simulation.

Initializes a [Statistics](#classStatistics) object. 
#### Parameters
* `Configuration*` config. Defines which configuration this statistics object should follow.

Contructor of [Statistics](#classStatistics) object.

#### `public string `[`get_usage_price`](#classStatistics_1af4c128bde8bed27787f5ecdb08bf9929)`()` {#classStatistics_1af4c128bde8bed27787f5ecdb08bf9929}

Public method. Returns the total usage price as a string.

#### Returns
string. Usage price string.

Returns system total usage price as a string with a precision of 2 decimal places.

#### `public string `[`get_machine_time`](#classStatistics_1afb354cc8fcd9ab43ec9c3d9e2880e660)`()` {#classStatistics_1afb354cc8fcd9ab43ec9c3d9e2880e660}

Public method. Returns the total machine time as a string.

#### Returns
string. Machine time string.

Returns the machine time as a string with the number of days, hours, minutes and seconds.

#### `public string `[`get_operational_cost`](#classStatistics_1a091d26462ea4db2b2a6032b94ff49a31)`()` {#classStatistics_1a091d26462ea4db2b2a6032b94ff49a31}

Public method. Returns the total operational cost as a string.

#### Returns
string. Operational cost string.

Returns system total operational cost as a string with a precision of 2 decimal places.

#### `public string `[`get_economic_balance`](#classStatistics_1a20e75d62f6802875eec1ebd8424d84b1)`()` {#classStatistics_1a20e75d62f6802875eec1ebd8424d84b1}

Public method. Returns the economic balance as a string.

#### Returns
string. Economic balance string.

Returns system economic balance as a string with a precision of 2 decimal places.

#### `public string `[`get_weekly_usage`](#classStatistics_1a6f5e39adedce4de0c0983619fb8498c8)`()` {#classStatistics_1a6f5e39adedce4de0c0983619fb8498c8}

Public method. Returns the weekly usage as a string.

#### Returns
string. [System](#classSystem) weekly usage.

Returns system weekly usage as a string.

#### `public string `[`get_short_ta`](#classStatistics_1a7858a6d068d7c56d29a5f54c20a8521c)`()` {#classStatistics_1a7858a6d068d7c56d29a5f54c20a8521c}

Public method. Returns the average turn around ratio of short jobs.

#### Returns
string. Turn around ratio of short jobs string.

Returns average of turn around times of short jobs as a string with a precision of 2 decimal places.

#### `public string `[`get_medium_ta`](#classStatistics_1a114925dbd18467fed3db887104d27807)`()` {#classStatistics_1a114925dbd18467fed3db887104d27807}

Public method. Returns the average turn around ratio of medium jobs.

#### Returns
string. Turn around ratio of medium jobs string.

Returns average of turn around times of medium jobs as a string with a precision of 2 decimal places.

#### `public string `[`get_large_ta`](#classStatistics_1a6f0aacba4f01c18cc9da75b1cb2f3e51)`()` {#classStatistics_1a6f0aacba4f01c18cc9da75b1cb2f3e51}

Public method. Returns the average turn around ratio of large jobs.

#### Returns
string. Turn around ratio of large jobs string.

Returns average of turn around times of large jobs as a string with a precision of 2 decimal places.

#### `public string `[`get_huge_ta`](#classStatistics_1a6afcfec266fe44d1c876be80f09f6de3)`()` {#classStatistics_1a6afcfec266fe44d1c876be80f09f6de3}

Public method. Returns the average turn around ratio of huge jobs.

#### Returns
string. Turn around ratio of huge jobs string.

Returns average of turn around times of huge jobs as a string with a precision of 2 decimal places.

#### `public string `[`get_short_wt`](#classStatistics_1abef59b8f494093e62ff1a27bd989e42a)`()` {#classStatistics_1abef59b8f494093e62ff1a27bd989e42a}

Public method. Returns the average waiting time of short jobs.

#### Returns
string. Average waiting time of short jobs string.

Returns average of waiting times of short jobs as a string with a precision of 2 decimal places.

#### `public string `[`get_medium_wt`](#classStatistics_1aa20489eecdafe0ebcac554f34b60caef)`()` {#classStatistics_1aa20489eecdafe0ebcac554f34b60caef}

Public method. Returns the average waiting time of medium jobs.

#### Returns
string. Average waiting time of medium jobs string.

Returns average of waiting times of medium jobs as a string with a precision of 2 decimal places.

#### `public string `[`get_large_wt`](#classStatistics_1a06c13d01f1a8ea83391628b9bf617a4f)`()` {#classStatistics_1a06c13d01f1a8ea83391628b9bf617a4f}

Public method. Returns the average waiting time of large jobs.

#### Returns
string. Average waiting time of large jobs string.

Returns average of waiting times of large jobs as a string with a precision of 2 decimal places.

#### `public string `[`get_huge_wt`](#classStatistics_1a17dc31579326d8463eba7dd661673f47)`()` {#classStatistics_1a17dc31579326d8463eba7dd661673f47}

Public method. Returns the average waiting time of huge jobs.

#### Returns
string. Average waiting time of huge jobs string.

Returns average of waiting times of huge jobs as a string with a precision of 2 decimal places.

#### `public void `[`add_usage_price`](#classStatistics_1af99eab950e1fa1a657332fface5dc13e)`(double price)` {#classStatistics_1af99eab950e1fa1a657332fface5dc13e}

Public method. Adds price to total usage price.

#### Parameters
* `double` price. Price to be added.

Adds usage price to system total usage price.

#### `public void `[`add_operational_cost`](#classStatistics_1a17bca1fa9938f98e93cebd56d428f9a4)`(double cost)` {#classStatistics_1a17bca1fa9938f98e93cebd56d428f9a4}

Public method. Adds cost to total operational cost.

#### Parameters
* `double` cost. Cost to be added.

Adds operational cost to system total operational cost.

#### `public void `[`add_machine_time`](#classStatistics_1a726b0734f8a0c86024543190ab3092ea)`(unsigned long long int time)` {#classStatistics_1a726b0734f8a0c86024543190ab3092ea}

Public method. Adds time to total machine time.

#### Parameters
* `unsigned` long long int time. Time in seconds to be added.

Adds time to system total machine time.

#### `public void `[`add_job`](#classStatistics_1a78e4c255a4999ebd6c8872eef6360427)`(time_t start,`[`Job`](#classJob)` job)` {#classStatistics_1a78e4c255a4999ebd6c8872eef6360427}

Public method. Adds job to waiting time and turn around vectors.

#### Parameters
* `time_t` start. Time of start. 

* `[Job](#classJob)` job. [Job](#classJob) to be added.

Adds job to waiting time and turn around ratio vectors according to its type. Increments the number of Short, Medium, Large or Huge jobs processed in the week of job start time.

# class `System` {#classSystem}

[System](#classSystem) class.

This object represents the computing system.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`System`](#classSystem_1a38c393cf990b65c13bf926c6e25c4f0a)`(`[`Configuration`](#classConfiguration)` * config)` | [System](#classSystem) object default contructor.
`public  `[`System`](#classSystem_1a4d2006a8a392e1c198fb988a7d125ac8)`(`[`Configuration`](#classConfiguration)` * config,vector< `[`User`](#classUser)` * > users,vector< `[`Job`](#classJob)` > jobs)` | [System](#classSystem) object contructor for custom tests.
`public string `[`get_results`](#classSystem_1adbb7e0745a7a25f8a598eaa6b04dd4ed)`()` | Public method. Fetchs results of statistics object, returning a string with a specific format.

## Members

#### `public  `[`System`](#classSystem_1a38c393cf990b65c13bf926c6e25c4f0a)`(`[`Configuration`](#classConfiguration)` * config)` {#classSystem_1a38c393cf990b65c13bf926c6e25c4f0a}

[System](#classSystem) object default contructor.

Initializes a [System](#classSystem) object. 
#### Parameters
* `[Configuration](#classConfiguration)` * config. [Configuration](#classConfiguration) to be followed by the simulation.

Default contructor of [System](#classSystem) object. Populates vector of users and jobs. Runs the scheduler algorithm and calculates the operating cost of the system.

#### `public  `[`System`](#classSystem_1a4d2006a8a392e1c198fb988a7d125ac8)`(`[`Configuration`](#classConfiguration)` * config,vector< `[`User`](#classUser)` * > users,vector< `[`Job`](#classJob)` > jobs)` {#classSystem_1a4d2006a8a392e1c198fb988a7d125ac8}

[System](#classSystem) object contructor for custom tests.

Initializes a [System](#classSystem) object. 
#### Parameters
* `[Configuration](#classConfiguration)` * config. [Configuration](#classConfiguration) to be followed by the simulation. 

* `vector<User*>` users. Simulated users vector. 

* `vector<Job>` jobs. Simulated jobs vector.

Alternative contructor of [System](#classSystem) object, indicated for testing purposes. Runs the scheduler algorithm and calculates the operating cost of the system.

#### `public string `[`get_results`](#classSystem_1adbb7e0745a7a25f8a598eaa6b04dd4ed)`()` {#classSystem_1adbb7e0745a7a25f8a598eaa6b04dd4ed}

Public method. Fetchs results of statistics object, returning a string with a specific format.

#### Returns
string. String with information about the outputs of the simulation.

Returns string with informations about the outputs of the simulation.

# class `User` {#classUser}

[System](#classSystem) class.

This object represents a simulated user.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`User`](#classUser_1a9ee57fd1e1dca94a043ad0f5a99ac2be)`(`[`Configuration`](#classConfiguration)` * config,int id,bool support)` | [User](#classUser) object default contructor.
`public bool `[`can_afford`](#classUser_1a256c7f780ea27a728b2bf391e0925728)`(`[`Job`](#classJob)` * job)` | Public method. Method to check if an [User](#classUser) can afford to run a given job.
`public void `[`pay`](#classUser_1ab960fea4dd1f6ea2439e410fb8cfd9bc)`(`[`Job`](#classJob)` * job)` | Public method. Decreases the user budget according to the price of a job.

## Members

#### `public  `[`User`](#classUser_1a9ee57fd1e1dca94a043ad0f5a99ac2be)`(`[`Configuration`](#classConfiguration)` * config,int id,bool support)` {#classUser_1a9ee57fd1e1dca94a043ad0f5a99ac2be}

[User](#classUser) object default contructor.

Initializes a [User](#classUser) object. 
#### Parameters
* `[Configuration](#classConfiguration)` * config. [Configuration](#classConfiguration) to be followed by the simulation. 

* `int` id. [User](#classUser) id, this value is unique between users. 

* `bool` support. The user is part of the IT Support if true.

Default contructor of [User](#classUser).

#### `public bool `[`can_afford`](#classUser_1a256c7f780ea27a728b2bf391e0925728)`(`[`Job`](#classJob)` * job)` {#classUser_1a256c7f780ea27a728b2bf391e0925728}

Public method. Method to check if an [User](#classUser) can afford to run a given job.

#### Parameters
* `[Job](#classJob)` * job. [Job](#classJob) to be paid. 

#### Returns
bool. True if user can afford the job, false if not.

Method to check if an user can afford for a given job.

#### `public void `[`pay`](#classUser_1ab960fea4dd1f6ea2439e410fb8cfd9bc)`(`[`Job`](#classJob)` * job)` {#classUser_1ab960fea4dd1f6ea2439e410fb8cfd9bc}

Public method. Decreases the user budget according to the price of a job.

#### Parameters
* `[Job](#classJob)` * job. [Job](#classJob) to be paid.

Method to decrease the user budget, according to the price of a given job.

# class `Week` {#classWeek}

[Week](#classWeek) class.

This object keeps information about number of jobs processed in a week by each queue.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Week`](#classWeek_1acde62b92be9795ba306655c67cb73657)`(time_t start,time_t end)` | [Week](#classWeek) object default contructor.
`public time_t `[`get_start`](#classWeek_1a09c3311872e50cc72900c97f5b2bde46)`()` | Public method. Returns the starting date of a job.
`public time_t `[`get_end`](#classWeek_1a9bc75154f4fab7823f0ea9e04a69296d)`()` | Public method. Returns the ending date of a job.
`public void `[`set_start`](#classWeek_1a583625ac54cdbf5b38caf23c8b76ae37)`(time_t start)` | Public method. Defines new starting date of a week.
`public void `[`add_job`](#classWeek_1ac5f28e3ca4f43b4c4d78f9a4e140c207)`(`[`Job`](#classJob)` job)` | Public method. Defines new starting date of a week.

## Members

#### `public  `[`Week`](#classWeek_1acde62b92be9795ba306655c67cb73657)`(time_t start,time_t end)` {#classWeek_1acde62b92be9795ba306655c67cb73657}

[Week](#classWeek) object default contructor.

Private unsigned int. Number of huge jobs processed.

Initializes a [Week](#classWeek) object. 
#### Parameters
* `time_t` start. Defines the stating date of the week. 

* `time_t` end. Defines the ending date of the week.

Contructor of [Week](#classWeek) object.

#### `public time_t `[`get_start`](#classWeek_1a09c3311872e50cc72900c97f5b2bde46)`()` {#classWeek_1a09c3311872e50cc72900c97f5b2bde46}

Public method. Returns the starting date of a job.

#### Returns
time_t. Date represented in UNIX timestamp.

Ŕeturns the starting time of a week.

#### `public time_t `[`get_end`](#classWeek_1a9bc75154f4fab7823f0ea9e04a69296d)`()` {#classWeek_1a9bc75154f4fab7823f0ea9e04a69296d}

Public method. Returns the ending date of a job.

#### Returns
time_t. Date represented in UNIX timestamp.

Ŕeturns the ending time of a week.

#### `public void `[`set_start`](#classWeek_1a583625ac54cdbf5b38caf23c8b76ae37)`(time_t start)` {#classWeek_1a583625ac54cdbf5b38caf23c8b76ae37}

Public method. Defines new starting date of a week.

#### Parameters
* `time_t` start. Starting date represented in UNIX timestamp.

Defines a start time of a week.

#### `public void `[`add_job`](#classWeek_1ac5f28e3ca4f43b4c4d78f9a4e140c207)`(`[`Job`](#classJob)` job)` {#classWeek_1ac5f28e3ca4f43b4c4d78f9a4e140c207}

Public method. Defines new starting date of a week.

#### Parameters
* `time_t` start. Starting date represented in UNIX timestamp.

Increments the number of jobs processed this week according to its type.

Generated by [Moxygen](https://sourcey.com/moxygen)