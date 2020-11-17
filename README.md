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
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
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
 >Factory Method
 https://github.com/cs100/final-project-jwall014-asu013-anaba002/blob/AyushClassDiagram/classDiagram.jpg
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
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
