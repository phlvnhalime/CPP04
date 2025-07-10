# 📦 CPP04 – Subtype Polymorphism, Abstract Classes, and Interfaces

Welcome to my repository for **CPP04**, the fifth module of the C++ curriculum at **42 School**.  
This project explores **Subtype Polymorphism**, **Abstract Classes**, **Virtual Functions**, and **Interface design patterns** using the **C++98 standard**.

---

## 🔍 Overview

This module covers advanced OOP concepts that enable true polymorphic behavior:
- **Virtual Functions** and **Dynamic Dispatch**
- **Subtype Polymorphism** through inheritance
- **Abstract Classes** and **Pure Virtual Functions**
- **Deep Copy vs Shallow Copy** semantics
- **Virtual Destructors** for proper cleanup
- **Memory Management** in polymorphic hierarchies
- **Interface Design Patterns** in C++

The goal is to understand how polymorphism enables writing flexible, extensible code that works with objects of different types through a common interface.

---

## 🛠️ Compilation Rules

- **Compiler:** `c++`
- **Flags:** `-Wall -Wextra -Werror -std=c++98`
- ❌ No external libraries  
- ❌ No C++11 (or later) features  
- ❌ STL usage is **forbidden** until Module 08
- ❌ Forbidden functions: `*printf()`, `*alloc()`, `free()`
- ✅ **Orthodox Canonical Form** required for all classes

---

## 📁 Project Structure

```plaintext
CPP04/
├── ex00/
├── ex01/
└── ex02/
```

Each folder demonstrates progressively advanced polymorphic concepts, from basic virtual functions to abstract classes.

---

## 🎭 Polymorphism Fundamentals

### **Virtual Functions**
```cpp
class Animal {
public:
    virtual void makeSound() const;  // Virtual function
    virtual ~Animal();               // Virtual destructor
};

class Dog : public Animal {
public:
    virtual void makeSound() const override;  // Override behavior
};
```

### **Dynamic Dispatch**
```cpp
Animal* animal = new Dog();
animal->makeSound();  // Calls Dog::makeSound(), not Animal::makeSound()
```

### **Abstract Classes**
```cpp
class Animal {
public:
    virtual void makeSound() const = 0;  // Pure virtual function
    virtual ~Animal() {}
};
// Animal cannot be instantiated directly
```

---

## 📘 Exercises Summary

### 🐾 ex00 – Polymorphism

**Goal:**  
Implement basic polymorphism with virtual functions and demonstrate the difference between virtual and non-virtual behavior.

**Class Hierarchy:**
```
Animal (base class)
├── Dog
└── Cat
```

**Key Features:**
- `Animal` base class with protected `std::string type`
- Virtual `makeSound()` function for polymorphic behavior
- `getType()` function to return animal type
- Proper constructor messages for debugging

**Polymorphic Behavior:**
```cpp
const Animal* dog = new Dog();
const Animal* cat = new Cat();

dog->makeSound();  // "Woof! Woof!"
cat->makeSound();  // "Meow! Meow!"
```

**Non-Virtual Comparison:**
- `WrongAnimal` and `WrongCat` classes
- Non-virtual functions show static binding
- Demonstrates why virtual functions are essential

**What I Learned:**
- **Virtual function** mechanics and syntax
- **Dynamic dispatch** vs **static binding**
- **Runtime polymorphism** through inheritance
- **Function overriding** in derived classes
- **Base class pointers** with derived objects

**Expected Output:**
```cpp
const Animal* animals[] = {new Dog(), new Cat()};
for (int i = 0; i < 2; i++) {
    animals[i]->makeSound();  // Calls correct derived version
}
```

### 🧠 ex01 – I don't want to set the world on fire

**Goal:**  
Implement proper memory management with polymorphic classes, focusing on **deep copy semantics** and **virtual destructors**.

**New Components:**
- `Brain` class with `std::string ideas[100]` array
- `Dog` and `Cat` contain `Brain*` attribute
- Dynamic allocation: `brain = new Brain()`

**Memory Management Requirements:**
- **Virtual destructors** for proper cleanup
- **Deep copy construction** and **assignment**
- **No memory leaks** when deleting through base pointer
- **Proper destruction order** in inheritance hierarchy

**Deep Copy Implementation:**
```cpp
Dog::Dog(const Dog& other) : Animal(other) {
    this->brain = new Brain(*other.brain);  // Deep copy
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);  // Deep copy
    }
    return *this;
}
```

**Critical Test Case:**
```cpp
const Animal* animals[4] = {
    new Dog(), new Dog(), new Cat(), new Cat()
};

for (int i = 0; i < 4; i++) {
    delete animals[i];  // Must call correct destructor
}
```

**What I Learned:**
- **Virtual destructors** necessity in inheritance
- **Deep copy vs shallow copy** distinction
- **Memory management** in polymorphic hierarchies
- **Resource cleanup** through proper destructors
- **Copy semantics** with dynamically allocated members

**Memory Safety Verification:**
- Test with valgrind or similar tools
- Ensure no memory leaks
- Verify proper destruction order

### 🔒 ex02 – Abstract class

**Goal:**  
Transform the `Animal` class into an **abstract class** to prevent direct instantiation while maintaining polymorphic behavior.

**Abstract Class Implementation:**
```cpp
class Animal {
protected:
    std::string type;
    
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    
    virtual void makeSound() const = 0;  // Pure virtual function
    std::string getType() const;
};
```

**Key Changes:**
- `makeSound()` becomes **pure virtual** (`= 0`)
- `Animal` cannot be instantiated directly
- Derived classes **must implement** `makeSound()`
- All other functionality remains unchanged

**Compilation Behavior:**
```cpp
// This will cause compilation error:
Animal* animal = new Animal();  // Error: cannot instantiate abstract class

// This still works:
Animal* animal = new Dog();     // OK: Dog implements makeSound()
```

**What I Learned:**
- **Pure virtual functions** syntax and behavior
- **Abstract class** design principles
- **Interface enforcement** through abstraction
- **Compilation-time safety** through abstract classes
- **Design patterns** for extensible hierarchies

**Benefits of Abstract Classes:**
- **Prevent invalid instantiation** of base concepts
- **Enforce interface implementation** in derived classes
- **Maintain polymorphic behavior** through base pointers
- **Provide common implementation** for shared functionality

---

### **Memory Leak Detection**
```bash
valgrind --leak-check=full ./program
# Should show "no leaks are possible"
```

---

## 📣 Final Notes

This module was crucial for understanding **true object-oriented programming**. The concepts learned here are fundamental to:

- **Design Patterns** implementation
- **Framework development**
- **Plugin architectures**
- **Extensible software design**

**Key Takeaways:**
- **Virtual functions** enable runtime polymorphism
- **Abstract classes** provide interface contracts
- **Deep copy** is essential with dynamic memory
- **Virtual destructors** prevent memory leaks
- **Polymorphism** enables flexible, extensible designs

💬 *"Polymorphism is not about inheritance, it's about substitutability!"* - Understanding when and how to use virtual functions is essential for clean OOP design.

The Animal hierarchy demonstrates how **polymorphism creates flexible, maintainable code** that can be extended with new animal types without modifying existing code. Perfect foundation for advanced design patterns! 🚀

---

**Author:** Halime Pehlivan.  
**School:** 42 Heilbronn
