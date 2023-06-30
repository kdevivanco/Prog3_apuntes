Creational Pattern in C++

A pattern, in general, refers back to the unique format which enables one to carry out positive responsibilities with ease. Technically, styles may be taken into consideration as gadgets that assist the applications in sharing the know-how in their layout.

Design Pattern: The time period layout sample is utilized in object-orientated terminology to carry out the responsibilities along with defining the objects, class, interface, inheritance hierarchies, and factoring them into lessons with relationships. Once these types of steps are taken into consideration as a sample they may be reused with the aid of using making use of them to numerous not unusual place problems.

Creational Patterns: Generally, a system has information about its object’s creation, composition, and representation. Creational patterns have handled everything from object creation to its representation. 

The system does not need to worry about how its objects are created, represented, etc. Such creational patterns are known as object creational patterns. That delegates object instantiation to another object.
In addition to this, there are creational patterns that can also manage the instantiation process of classes by using the concept of inheritance. These patterns are called creational patterns, out of these two patterns, more importance is given to object creational patterns. They define a small set of fundamental behaviors that can perform more complex tasks rather than defining a fixed set of behaviors.
Creational patterns contain information about concrete classes, that are mostly used by the system.
They do not provide information about how different instances of concrete classes are created and how they are combined together.
The only thing the system knows about its objects is the interfaces of objects that are declared by the abstract classes.
Based on the above two categories of creational patterns i.e. object and class, there are 5 types of creational patterns with all of them being object creational patterns except the Factory Method pattern, which is a class creational pattern.


Abstract Factory Patterns
Builder Pattern
Factory  Method Pattern
Prototype Pattern
Singleton Pattern
Let’s start discussing these patterns in detail.

1. Abstract Factory Patterns
Abstract Factory pattern is an object creational pattern which is also known as a kit. The intent of this pattern is to instantiate a set of related objects for the specific client through an interface in such a way that none of its concrete classes is specified.

Example: Consider the example of a maze game in which a member function create() of a class  Maze_Game is used to build a maze. The problem with that code is, it was written to create only two rooms with a door between them. Hence, this makes it difficult to create a maze with different components. To overcome this problem, a MazeFactory (MF) class is created that creates rooms, according to the specification of doors, walls, and rooms specified by the programmer.

Solution:
```

C++
#include <iostream>
using namespace std;
 
// Code of  Maze_Factory Class  is flows,
 
class Maze_Factory {
public:
    Maze_Factory(); // Constructor
 
    virtual Maze* createMaze() const { return new Maze; }
 
    virtual Rooms* createsRooms(int rno) const
    {
        return new Rooms(rno);
    }
 
    virtual Wall* createsWall() const { return new wall; }
 
    virtual Wall* createsWall() const;
    {
        return new Wall;
    }
 
    virtual Door* createsDoor(Room* ro1, Room*, ro2) const
    {
        return new Door(ro1, ro2);
    }
};
// Therefore the code for creating a maze using an object of
// A Maze_Factory as a parameter is given below,
 
Maze* Maze_Game::create(Maze_Factory& f)
{
    Maze* m = f.createMaze();
    Room* ro1 = f.createRoom(1);
    room* ro2 = f.createRoom(2);
    Door* d = f.create Door(ro1, ro2);
    m-- > addRoom(ro1);
    m-- > addRoom(ro2);
 
    // create room1
    ro1-- > setSide(North, f.createwall());
    ro1-- > setSide(south, f.createwall());
    ro1-- > setSide(East, d);
    ro1-- > setSide(West, f.createwall());
 
    // create room2
    ro2-- > setSide(North, f.createwall());
    ro2-- > setSide(South, f.createwall());
    ro2-- > setSide(East, f.createWall());
    ro2-- > setSide(West, d);
    return m;
}

```

2. Builder Patterns
The Intent of a builder design pattern is to build a complex object using an algorithm in such a way that its construction is independent of the way it is represented. By doing so construction process used for creating a particularly complex object can be used to represent the same object in different ways.

Example: Consider the maze game example. The MazeUsing-Builder class defines an interface for creating a maze.
```
C++
#include <iostream>
using namespace std;
 
class MazeUsingBuilder {
public:
    virtual void createMaze() {}
    virtual void createMaze(into) {}
    virtual void createDoor(int fromRoom,
                            int toRoom)
    {
    }
 
    virtual Maze* getMaze()
    {
      return 0;
    }
 
protected:
    MazeUsingBuilder();
};

```

The above class consists of 4 methods where the methods createMaze(), create room(), and createDoor() create a maze, rooms with particular room number and door between numbered rooms respectively. The getMaze()method returns the maze to the client but, by default these operations do nothing. They are overridden by subclasses of MazeUsingBuilder class.

The MazeUsingBuilder can be used by a program that builds a maze as a parameter. Therefore, the modified version of create() is given below:

```
C++
#include <iostream>
using namespace std;
 
 Maze* Maze*_Game :: create(MazeUsingBuilder& b)
 {
   b.createMaze();
   b.createRoom(1);
   b.createRoom(2);
   b.createDoor(1,2);
   return.bgetMaze();
 }

 ```
 
From the above code, it can be observed that the MazeUsingBuilder class hides the way in which the maze is internally represented. That is it, does not show the class definition of rooms, doors, and walls and the way in which these parts are combined together for constructing a complete maze.

3. Factory Method Pattern
The Factory Method pattern is a class creational pattern and is also known as a virtual constructor. The Intent of the factory method is to define an interface creating an object and defer the instantiation of a class to subclass.

Example: Consider the maze game example. As already mentioned, the problem with createMaze()is that the MazeUsingFactory defines the factory methods for different components like the maze, rooms, and walls. The factory methods allow the subclasses to choose these components.

Solution: The code of class MazeUsingFactory with Factory methods is as follows:

C++
class MazeUsingFactory
{
  public:
   
  virtual Maze*createMaze()const
  {
    return new Maze;
  }
   
  virtual Room*createRoom()const
  {
    return new Room(N);
  }
   
  virtual Wall*create()const
  {
    return new Wall;
  }
   
  virtual Door*createDoor(Room*ro1,Room*ro2)const
  {
    return new Door(ro1,ro2);
  }
}
Here, the factory method are createMaze(),createRoom(),createDoor()and createWall(). All these methods returns the respective components of the maze.

Hence the code for create()for creating a maze using Factory methods is as follows,

C++
Maze* Maze_Game ::create();
{
  Maze* m = createMaze();
  Room* ro1 = createRoom(1);
  Room* ro2 = createRoom(2);
  Door*d = createDoor(ro1,ro2);
  m-->addRoom(ro1);
  m-->addRoom(ro2);
  ro1-->setSide(North,createWall());
  ro1-->setSide(South,createWall());
  ro1-->setSide(East,d);
  ro1-->setSide(West,createWall());
  ro2-->setSide(North,createWall());
  ro2-->setSide(South,createWall());
  ro2-->setSide(East,createWall());
  ro2-->setSide(West,d);
  return m;
}
4. Prototype Pattern
Prototype pattern specifies how particular types of objects are created by using the prototypical instance of the particular class and also how other objects are generated by cloning this prototype.

Example: A subclass of MazUsingFactory class is created called MazeUsingPrototype. In this class, the prototype of objects of Maze, Room, Wall, and Door classes are first created and then initialized. This Initialization is done through a parameterized constructor which is added to MazeUsingFactory.

Solution: The code for the creation of the prototype is given below,

C++
class MazeUsingPrototype : public MazeUsingFactory
{
public:
    MazeUsingProtype(Maze*, Wall*, Room*, Door*);
    virtual Maze* createMaze() const;
    virtual Room* createRoom(int) const;
    virtual Wall* createWall() const;
    virtual Door* createDoor(Room*, Room*) const;
 
private:
    Maze* Maze_prototype;
    Room* Room_protype;
    Wall* Wall_prototype;
    Door* Door_prototype;
}
 
MazeUsingPrototype::MazeUsingProtype
(Maze* mz, Wall* wl, Room* rm, Door* dr)
{
    Maze_prototype = mz;
    Wall_Prototype = wl;
    Room_Prototype = rm;
    Door_Prototype = dr;
}
The code for the above process is as follows,

C++
Room* MazeUsingPrototyping::createRoom
(int N)const;
{
  Room* r = Room_Prototype-->clone;
  r-->Initialize(N);
  return r;
}
 
Wall* MazeUsingPrototype::createWall()
  const;
{
  return Wall_Prototype-->clone;
}
 
Door* MazeUsingPrototype::createDoor
(Room*ro1, Room* ro2)const;
{
  Door*d = Door_Prototye-->clone();
  d-->Initialize(ro1,ro2);
  return d;
}
In order to create a prototypical instance or default maze. Prototype of MazeUsingPrototypeclass is created and initialized with the prototype of the component of the maze.

C++
Maze_Game g;
MazeUsingPrototype MyMaze
(new Maze,new Wall,new Room, new Door);
Maze* m = g.create(MyMaze);
Here, MyMaze is the prototype instance of MazeUsingPrototype.

5. Singleton Pattern
Singleton Pattern is one of the object creational patterns, singleton pattern makes sure that a particular class only has a single instance. It also enables that instance to be globally accessible.

Example:

C++
class Singleton
 {
   public:
   static Singleton* Instance();
   protected:
   Singleton();
   private:
   static Singleton* oneInstance();
 };
// implementation of Instance() is given below
 
Singleton* Singleton::oneInstance = 0;
Singleton* Singleton:: Instance();
{
  if(oneInstance==0)
  {
    oneInstance = new Singleton;
  }
  return oneInstance;
}
Here, for the Singleton class, it can be observed that the constructor of this class is of type protected. Hence when any client tries to directly instantiate this class or create another instance, an error message will be displayed during the compilation of this code. Therefore, this ensures that a class can have no more than one instance.         

Features of Creational Patterns:
Creational patterns handle object creation and representation. They separate the use of objects from their creation logic. The two important features provided by the creational pattern are:

They encapsulate knowledge about, which concrete class to create and instantiate.
They conceal the process of object creation, thereby separating the use of objects from their creation logic.
Using the creational patterns, the developers just have to be concerned about using the class without worrying about how its concrete classes are created or instantiated.

Applications: 
When the configuration of a system is done using one of the multiple sets of objects.
When the system does not need to worry about the process involved in an instantiation of its objects.
When a user wants to display a class library of objects in such a way that only their interfaces are shown.