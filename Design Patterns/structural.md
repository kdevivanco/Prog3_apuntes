## Adapter Pattern

This pattern is easy to understand as the real world is full of adapters.   For example consider a USB to Ethernet adapter. We need this when we have an Ethernet interface on one end and USB on the other. Since they are incompatible with each other. we use an adapter that converts one to other. This example is pretty analogous to Object Oriented Adapters. In design, adapters are used when we have a class (Client) expecting some type of object and we have an object (Adaptee) offering the same features but exposing a different interface.

### To use an adapter:

The client makes a request to the adapter by calling a method on it using the target interface.
The adapter translates that request on the adaptee using the adaptee interface.
Client receive the results of the call and is unaware of adapter’s presence.
Definition: The adapter pattern convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn’t otherwise because of incompatible interfaces. Class Diagram: ad3 The client sees only the target interface and not the adapter. The adapter implements the target interface. Adapter delegates all requests to Adaptee. Example:

Suppose you have a Bird class with fly() , and makeSound()methods. And also a ToyDuck class with squeak() method. Let’s assume that you are short on ToyDuck objects and you would like to use Bird objects in their place. Birds have some similar functionality but implement a different interface, so we can’t use them directly. So we will use adapter pattern. Here our client would be ToyDuck and adaptee would be Bird.

```
#include <iostream>
 
class Bird
{
  public:
    virtual void fly() = 0;
    virtual void makeSound() = 0;
};
 
class Sparrow : public Bird
{
  public:
    void fly() override
    {
        std::cout << "Flying" << std::endl;
    }
    void makeSound() override
    {
        std::cout << "Chirp Chirp" << std::endl;
    }
};
 
class ToyDuck
{
  public:
    virtual void squeak() = 0;
};
 
class PlasticToyDuck : public ToyDuck
{
  public:
    void squeak() override
    {
        std::cout << "Squeak" << std::endl;
    }
};
 
class BirdAdapter : public ToyDuck
{
  public:
    BirdAdapter(Bird &bird) : bird_(bird) {}
    void squeak() override
    {
        bird_.makeSound();
    }
 
  private:
    Bird &bird_;
};
 
int main()
{
    Sparrow sparrow;
    PlasticToyDuck toyDuck;
 
    ToyDuck &birdAdapter = *(new BirdAdapter(sparrow));
 
    std::cout << "Sparrow..." << std::endl;
    sparrow.fly();
    sparrow.makeSound();
 
    std::cout << "ToyDuck..." << std::endl;
    toyDuck.squeak();
 
    std::cout << "BirdAdapter..." << std::endl;
    birdAdapter.squeak();
 
    return 0;
}
// This code is contributed by Ahmed Izz Murtaja

```

Explanation : Suppose we have a bird that can makeSound(), and we have a plastic toy duck that can squeak(). Now suppose our client changes the requirement and he wants the toyDuck to makeSound than ? Simple solution is that we will just change the implementation class to the new adapter class and tell the client to pass the instance of the bird(which wants to squeak()) to that class. Before : ToyDuck toyDuck = new PlasticToyDuck(); After : ToyDuck toyDuck = new BirdAdapter(sparrow); You can see that by changing just one line the toyDuck can now do Chirp Chirp !! Object Adapter Vs Class Adapter The adapter pattern we have implemented above is called Object Adapter Pattern because the adapter holds an instance of adaptee. There is also another type called Class Adapter Pattern which use inheritance instead of composition but you require multiple inheritance to implement it. Class diagram of Class Adapter Pattern: pattern4 Here instead of having an adaptee object inside adapter (composition) to make use of its functionality adapter inherits the adaptee. Since multiple inheritance is not supported by many languages including java and is associated with many problems we have not shown implementation using class adapter pattern. Advantages:

Helps achieve reusability and flexibility.
Client class is not complicated by having to use a different interface and can use polymorphism to swap between different implementations of adapters.



Bridge Design Pattern
Read
Discuss

The Bridge design pattern allows you to separate the abstraction from the implementation. It is a structural design pattern. 

There are 2 parts in Bridge design pattern : 

Abstraction
Implementation
This is a design mechanism that encapsulates an implementation class inside of an interface class.  

The bridge pattern allows the Abstraction and the Implementation to be developed independently and the client code can access only the Abstraction part without being concerned about the Implementation part.
The abstraction is an interface or abstract class and the implementer is also an interface or abstract class.
The abstraction contains a reference to the implementer. Children of the abstraction are referred to as refined abstractions, and children of the implementer are concrete implementers. Since we can change the reference to the implementer in the abstraction, we are able to change the abstraction’s implementer at run-time. Changes to the implementer do not affect client code.
It increases the loose coupling between class abstraction and it’s implementation.
UML Diagram of Bridge Design Pattern




Elements of Bridge Design Pattern 

Abstraction – core of the bridge design pattern and defines the crux. Contains a reference to the implementer.
Refined Abstraction – Extends the abstraction takes the finer detail one level below. Hides the finer elements from implementers.
Implementer – It defines the interface for implementation classes. This interface does not need to correspond directly to the abstraction interface and can be very different. Abstraction imp provides an implementation in terms of operations provided by the Implementer interface.
Concrete Implementation – Implements the above implementer by providing the concrete implementation.
Lets see an Example of Bridge Design Pattern :  


Advantages 

Bridge pattern decouple an abstraction from its implementation so that the two can vary independently.
It is used mainly for implementing platform independence features.
It adds one more method level redirection to achieve the objective.
Publish abstraction interface in a separate inheritance hierarchy, and put the implementation in its own inheritance hierarchy.
Use bridge pattern to run-time binding of the implementation.
Use bridge pattern to map orthogonal class hierarchies
Bridge is designed up-front to let the abstraction and the implementation vary independently.

# Composite 
Composite pattern is a partitioning design pattern and describes a group of objects that is treated the same way as a single instance of the same type of object. The intent of a composite is to “compose” objects into tree structures to represent part-whole hierarchies. It allows you to have a tree structure and ask each node in the tree structure to perform a task.

As described by Gof, “Compose objects into tree structure to represent part-whole hierarchies. Composite lets client treat individual objects and compositions of objects uniformly”.
When dealing with Tree-structured data, programmers often have to discriminate between a leaf-node and a branch. This makes code more complex, and therefore, error prone. The solution is an interface that allows treating complex and primitive objects uniformly.
In object-oriented programming, a composite is an object designed as a composition of one-or-more similar objects, all exhibiting similar functionality. This is known as a “has-a” relationship between objects.
The key concept is that you can manipulate a single instance of the object just as you would manipulate a group of them. The operations you can perform on all the composite objects often have a least common denominator relationship.
The Composite Pattern has four participants:

Component – Component declares the interface for objects in the composition and for accessing and managing its child components. It also implements default behavior for the interface common to all classes as appropriate.
Leaf – Leaf defines behavior for primitive objects in the composition. It represents leaf objects in the composition.
Composite – Composite stores child components and implements child related operations in the component interface.
Client – Client manipulates the objects in the composition through the component interface.
Client use the component class interface to interact with objects in the composition structure. If recipient is a leaf then request is handled directly. If recipient is a composite, then it usually forwards request to its child components, possibly performing additional operations before and after forwarding.

Real Life example


In an organization, It have general managers and under general managers, there can be managers and under managers there can be developers. Now you can set a tree structure and ask each node to perform common operation like getSalary().
Composite design pattern treats each node in two ways:
1) Composite – Composite means it can have other objects below it.
2) leaf – leaf means it has no objects below it.

Tree structure:

Tree
The above figure shows a typical Composite object structure. As you can see, there can be many children to a single parent i.e. Composite, but only one parent per child.