# Group Verifier (Modern Algebra)
 > Authors: [Ayush Nabar](https://github.com/ayushnabar), [Angela Su](https://github.com/Angela-Su), [Josiah Wallis](https://github.com/Josiah-Wallis)

Given a **set of real numbers** and a **mathematical operation** in the form of a string as input, our group package will **verify** that the combination of inputs produces a valid [mathematical group](https://en.wikipedia.org/wiki/Group_(mathematics)). The implementation utilizes the **abstract factory, strategy, and memento design patterns**.

## Class Diagrams
* **Abstract Factory Method**: This method parses the mathematical string input and dynamically produces an operation object for use in the verification process. All standard mathematical operations can be produced as well as the power function, mod function, and a combination of functions.
 ![alt text](https://www.dropbox.com/s/xaf7r27cgiugd64/FactoryDiagram.jpg?dl=0&raw=1)
 
 * **Strategy Method**: The `Verification` class contains all the necessary conditions for verifying a given set of numbers is a mathematical group with the provided operation. The operaton is checked to be **associative** and **commutative**, the existence of **numerical inverses** and **identities** with respect to the operation is checked, and the number set is checked for **closure over the operation**.
 ![alt text](https://www.dropbox.com/s/64v7wv854v1rj09/Strategy.jpg?dl=0&raw=1)

 * **Memento Method**: The memento method allows for alteration of the group object by **providing automatic and manual save points for the state of the group**. When a group object is verifiably a mathematical group, the state is saved in case a **rollback** is required in the future, say if numbers are added to the set that violate the group conditions.
 ![alt text](https://www.dropbox.com/s/sbyzm5tphwx598n/updated_again.PNG?dl=0&raw=1)

 ## Usage
 A typical use case is provided below to start verifying sets as groups:
 
 ```c++
#include "group_header/group.hpp"

using namespace std;

int main(){
    set<Op*>* stuff = new set<Op*> {new Op(1), new Op(5)};              // Creates set {1, 5}
    string op = "modm6";                                                // Multiplication mod 6
    
    Group* group = new Group(stuff, op);                                // Instantiate Group object
    
    if(group->is_group())                                               // Checks all mathematical group conditions
        cout << "Hazzah! This is a mathematical group!" << endl;
    else
        cout << "This set does not satisfy all group requirements." << endl;
        
    return 0;
}
 ```
 
 ## Installation/Documentation
 * **How to use**
   1. Clone the repository to a local directory and compile the given cpp files
   2. For any file that wants to instantiate a group, include group.hpp and op.hpp
   3. Instantiate a set pointer of Op pointers and create a string operation using the guidelines presented in the **Important Info** section
   4. Pass the set and the operation to the Group constructor when instantiating said group
   5. Use Group::is_group() to verify
 * **Important Info**
    - **string operation formats**:
      1. An operation that includes a "placement definition." For example, "a+b-2" will define an operation where if we pass in a left and right operand, it will calculate (Left Op) + (Right Op) - 2. The program assumes an "a" will be passed in first followed by a "b" somewhere else in the string. There is also no doubling up, such as "a+a" and there must be no spaces or extraneous characters within the string definition. On a final note, precedence is not accounted for
      2. A single binary operation as follows: "+", "-", "\*", "/", "\*\*"
      3. A modular operation in one of the two following ways: "modpx", "modmx". The first format is modular addition mod x while the second format is modular multiplication mod x.
  * **Group Functionality**
    - There are three group constructors:
      1. **Group()** which sets its set to nullptr and its string to the empty string
      2. **Group(string)** which sets its set to nullptr and initializes its string component
      3. **Group(set<Op\*>\*, string)** which sets its set and string to the passed in arguments
    - **order()** returns the number of elements in the Group
    - **associated_set()** returns the immutable version of the set associated with the Group
    - **binary_operation()** returns the associated binary operation of the Group
    - **empty()** returns true or false, depending on if the Group's set is nullptr (true), size 0 (true), or if it contains at least one element (false)
    - **set_group(set<Op\*>\*)** sets the Group's group variable to the passed in set
    - **set_binary_operation(string)** sets the Group's binary_op variable
    - **insert(Op\*)** adds a passed in Op* to the Group's group variable if the Op* is not currently in it already
    - **remove(double)** deletes the Op* that evaluates to the passed double value if it's in the group variable
    - **mutable_set()** returns the associated group variable of the Group, but as a set that can be changed without altering the inner workings of the original group
    - **print()** prints out all elements in the group variable in the order they've been inserted or passed in
    - **is_group()** returns true or false depending on whether or not the Group satisfies all conditions to be an algebraic group (see [this](https://en.wikipedia.org/wiki/Group_(mathematics)))
    - **undo(int)** sets the group variable to the set associated with the last instance the Group was verified to be an algebraic group (is_group() == true) when int == 1. When int == 0, this function will set the group variable to an instance of the group before the last change that was made to the group. For example, if we add an element to the group and we undo(0), the group will be rolled back to before the insertion of said element
    - **back_track(int)** rolls the group variable back to an instance int saves ago starting from int == 0
    - **safe_save()** checks to see if the current Group is an algebraic group, and if so it saves this instance, if not it outputs an error.
    - **force_save()** saves the current inner workings of this set as an instance we can go back to
    - **num_saves()** returns the number of saves available to roll back to
 
 ## Testing
Our project was tested and validated by passing in mathematically verified Groups to our functions to make sure they pass, and mathematically verified non-Groups that should make our tests fail. These verified groups include the following **Finitely Generated Abelian Groups**:
* **Cyclic Modular Groups**
* **Klein 4-Groups**
* **Non-Cyclic Modular Groups**

Additionally, we formed basic sets and operations that do not work well together, and don't form mathematical groups. This combination of objects can be **verified mathematically**. In general, we used **googletests** to verify our calculations and assumptions with respect to the passed in groups and operations.

# Contact
Please send any questions, comments, or inquiries to jwall014@ucr.edu.
 
