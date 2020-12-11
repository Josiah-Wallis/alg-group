 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Algebraic Groups
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: \<[Ayush Nabar](https://github.com/ayushnabar), [Angela Su](https://github.com/Angela-Su), [Josiah Wallis](https://github.com/cheesejacker)\>
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
 >   * This project is interesting to us because it may provide a workable algebraic group verifier for mathematicians who use C++. There are libraries and tools in python that many people flock to, but for those whose native language is C++, this handy class may prove useful for checking if some set is in fact an algebraic group. Additionally, this project is interesting because it may prove useful in a current widescale SageTex program where mathematicians hope to make an AI or program that can verify mathematical proofs.
 
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++
    
 > * What will be the input/output of your project?
 >   * The input of our project will be a numerical set of data, specifically within the set data structure. A string or set of operations will be entered, as the console should request. Additionally, further inputs or preferences will be prompted for the user of this program that are specific to the algebraic group they are making. The output of our program will be a series of output messages verifying the object that has been created is in fact an algebraic group, and upon the user's request will output additional information such as the group's cardinality, existence of inverses, existence of identity elements, and whether or not the operation bound to the group is associative.
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Factory: We'll use this pattern to select which operation our group will be equipped with. Given an operation tree, this method will also help form a custom operation that our group will be equipped with. We will try to have the factory parse a string of operations, but if this doesn't run smoothly, the input will be an operation tree or a single operation that's been previously defined like multiplication or addition.
 >   * Strategy: The strategy pattern will allow us to store and dynamically use algorithms that verify our set is an algebraic group. It will contain 3-5 standard algorithms or methods that check the primary requirements for a set to be considered a group. Additionally, there will be smaller methods that can find the identity element and inverse element with respect to a given input, if there are such elements.
 >   * Memento: This pattern will be used for two purposes. To our understanding of this pattern, we'll use it to save individual states of our set. We'll save the state of the set then we'll add an element and perform various methods or functions to verify our set still holds certain properties, or pass certain tests. Also, we'll use this pattern to save the state of the set when we know it is verifiably a group. This is useful because we may add many elements to the set at a time, and if we don't know when the set stopped being an algebraic group, we can roll it back to its previous state.

 > * This description should be in enough detail that the TA/instructor can determine the complexity of the project and if it is sufficient for the team members to complete in the time allotted. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
> * Abstract Factory Method: Our project uses the Factory Pattern to dynamically create concrete operations. Our factory can create six operations: the five base operations from lab four and a custom operation. The AbstractFactory contains the parse() function which OpFactory must implement. Our OpFactory parse() function takes in Base* left and Base* right, which are two operands; string operation, which is only used to denote what operation should be returned; and int custom, which just tells us if the input is a custom operation, int = 1 for custom; otherwise, int = 0. 
 ![alt text](https://github.com/cs100/final-project-jwall014-asu013-anaba002/blob/master/FactoryDiagram.jpg)
 
 > * Strategy Method: Within the project, we want to be able to have a function verify() and function setGroup() both of which are in the Verifier Class (the Strategy). We also have Verification, which is the context, allowing us to communicate with the Verifier. The Verification class will act as a container of Verifier objects, allowing us to push_back verifiers if the object we're passing to it is not currently in the vector. Additionally, bool[] check takes in a range from num1 to num2, returning an array of bools for the results of verify() for the strategies from index num1 to num2 of the vector. Finally, the pass() function takes in the group we'll be analyzing and "passes" it over to each of the verifiers in the vector. The verify() checks if the input fits the requirements for a group, based on definition, and returns true or false based on if said requirements are met. For example, for Inverse, verify() would check if every element has an inverse, for Associative, verify() would check if the associative property applies, and under Commutative, verify() would check if the commutative property is valid. Then the setGroup() function stores the group that we are going to verify which makes it accessible in the subclasses: Associative, Commutative, Inverse, Closure, and Identity. This should pass in a Group * group which should be the group the subclasses check. All subclasses should also include the bool, verify(). 
 ![alt text](https://github.com/cs100/final-project-jwall014-asu013-anaba002/blob/master/Strategy.jpg)

 > * Memento Method: For this project, we want to be able to save the state of our algebraic group when we know it has been verified to be, in fact, an algebraic group. This means it has passed all of the strategy verifications we've implemented. Every time a group has been verified, a version of itself will be saved as a memento. The GroupBank class will act as our originator, instantiating and being the user's proxy to access the memento. The GoodGroup class will be our primary memento, the class that holds one given state of a group at a time. The caretaker will be a set of functions or methods that allow us to interact with the memento itself without changing the inner workings or state of the object.
 ![alt text](https://github.com/cs100/final-project-jwall014-asu013-anaba002/blob/master/updated_again.PNG)
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 > * **How to use**
 >   1. Clone the repository to a local directory and compile the given cpp files
 >   2. For any file that wants to instantiate a group, include group.hpp and op.hpp
 >   3. Instantiate a set pointer of Op pointers and create a string operation using the guidelines presented in the **Important Info** section
 >   4. Pass the set and the operation to the Group constructor when instantiating said group
 >   5. Use Group::is_group() to return a bool, stating whether or not the set equipped with the given operation is an algebraic group
 > * **Important Info**
 >   - The Group class accepts a set<Op*>* as its first argument and a string as its second argument
 >   - The string can be in one of the following formats:
 >     1. An operation that includes a "placement definition." For example, "a+b-2" will define an operation where if we pass in a left and right operand, it will calculate (Left Op) + (Right Op) - 2. The program assumes an "a" will be passed in first followed by a "b" somewhere else in the string. There is also no doubling up, such as "a+a" and there must be no spaces or extraneous characters within the string definition. On a final note, precedence is not accounted for
 >     2. A single binary operation as follows: "+", "-", "\*", "/", "\*\*"
 >     3. A modular operation in one of the two following ways: "modpx", "modmx". The first format is modular addition mod x while the second format is modular multiplication mod x.
 > * **Group Functionality**
 >   - There are three group constructors:
 >     1. Group() which sets its set to nullptr and its string to the empty string
 >     2. Group(string) which sets its set to nullptr and initializes its string component
 >     3. Group(set<Op*>\*, string) which sets its set and string to the passed in arguments
 >   - order() returns the number of elements in the Group
 >   - associated_set() returns the immutable version of the set associated with the Group
 >   - binary_operation() returns the associated binary operation of the Group
 >   - empty() returns true or false, depending on if the Group's set is nullptr (true), size 0 (true), or if it contains at least one element (false)
 >   - set_group(set<Op*>\*) sets the Group's group variable to the passed in set
 >   - set_binary_operation(string) sets the Group's binary_op variable
 >   - insert(Op*) adds a passed in Op* to the Group's group variable if the Op* is not currently in it already
 >   - remove(double) deletes the Op* that evaluates to the passed double value if it's in the group variable
 >   - mutable_set() returns the associated group variable of the Group, but as a set that can be changed without altering the inner workings of the original group
 >   - print() prints out all elements in the group variable in the order they've been inserted or passed in
 >   - is_group() returns true or false depending on whether or not the Group satisfies all conditions to be an algebraic group (see [this](https://en.wikipedia.org/wiki/Group_(mathematics)))
 >   - undo(int) sets the group variable to the set associated with the last instance the Group was verified to be an algebraic group (is_group() == true) when int == 1. When int == 0, this function will set the group variable to an instance of the group before the last change that was made to the group. For example, if we add an element to the group and we undo(0), the group will be rolled back to before the insertion of said element
 >   - back_track(int) rolls the group variable back to an instance int saves ago starting from int == 0
 >   - safe_save() checks to see if the current Group is an algebraic group, and if so it saves this instance, if not it outputs an error.
 >   - force_save() saves the current inner workings of this set as an instance we can go back to
 >   - num_saves() returns the number of saves available to roll back to
 
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
