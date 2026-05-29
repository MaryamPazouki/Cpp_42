/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpazouki <mpazouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:46:16 by mpazouki          #+#    #+#             */
/*   Updated: 2026/05/29 08:08:10 by mpazouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
This exercise is 100% about RTTI (Run-Time Type Information), specifically:

✔ Polymorphism
✔ Dynamic casting (dynamic_cast)
✔ Type identification without typeinfo
✔ Using references and pointers with polymorphism

This assignment wants to ensure you understand:

How dynamic_cast works on polymorphic types

The difference between pointer casting and reference casting

Why a polymorphic base class must have a virtual destructor

How to detect real type (A/B/C) when you only have a Base* or Base&**

*/


#include <iostream>

#include "generate.hpp"
#include "identify.hpp"

int main(){
    Base *p = generate();
    
    std::cout << "Identify using pointer: ";
    identify(p);
    
    std::cout << "Identify using reference: ";
    identify(*p);

    delete p;

    return 0;
}




/*---------------------------------------------------------------------*/
/* comparision between dynamic_cast vs static_cast vs reinterpret_cast*/
/*---------------------------------------------------------------------*/
/* 

Compile‑time type information is known and fixed during compilation.
Run‑time type information (RTTI) is discovered while the program is running, 
using mechanisms like dynamic_cast and typeid. 


✅ 1. static_cast
✔ What it does

Performs compile-time checked conversions.

Used for safe, known conversions.

Works with:

Numeric conversions (int → float)

Upcasting (child → parent)

Some downcasting (parent → child), but unsafe

✔ When to use it

When you are sure that the conversion is valid.

When runtime type safety is not required.

❌ Dangers

Downcasting with static_cast can cause undefined behavior:

Base* b = new Base();
Derived* d = static_cast<Derived*>(b);  // ❌ Dangerous! b is not a Derived

Example
float f = static_cast<float>(42);

✅ 2. dynamic_cast
✔ What it does

Performs runtime type checking.

Only works with polymorphic types → types with at least one virtual function.

Safe downcasting.

Uses RTTI (Run-Time Type Information).

✔ When to use it

When you want to check the actual runtime type of an object.

When downcasting through inheritance hierarchies.

✔ How it behaves
Cast form	Success	Failure
dynamic_cast<T*>(p)	returns pointer	returns nullptr
dynamic_cast<T&>(p)	continues	throws std::bad_cast
Example
Base* p = generate();

if (dynamic_cast<A*>(p))
    std::cout << "A\n";


This is the cast your assignment is forcing you to use.

❌ 3. reinterpret_cast
✔ What it does

Performs bit-level reinterpretation.

No safety, no type checking.

Used for:

raw memory operations

low-level casting

converting pointers to integers and back (like in Module 06 ex01!)

❌ Dangers

You can cast anything to anything, often producing meaningless values.

Example:

int* i = reinterpret_cast<int*>(0xdeadbeef); // ❌ dangerous

Safe-ish example (Module 06 ex01)
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
Data* data = reinterpret_cast<Data*>(raw);


This is the correct usage: serializing a pointer value.

🔥 Summary Table (Easy to Learn)
                    Feature	static_cast	dynamic_cast	reinterpret_cast
Checked at runtime?	    ❌ No	           ✔Yes	        ❌ No
Safe?	                ✔ Usually	        ✔Yes	     ❌ No
Requires polymorphism?	❌ No	            ✔ Yes	    ❌ No
Used for downcasting?	⚠ Allowed but unsafe   ✔ Yes, safe	❌ Extremely unsafe
Pointer → Integer?	    ❌ No	                ❌ No	✔ Yes
Cost	                Very fast	        Slower (RTTI)	Very fast
*/

/* static_cast is a compile‑time cast.
dynamic_cast is a run‑time cast that uses RTTI and works only with polymorphic classes. */

/* ----------------------- -------------------------------------------- */
/* dynamic_cast uses Run‑Time Type Information to check if the cast is valid.

✔️ Requirements
Base class must have at least one virtual function
Works only with pointers and references

✔️ Behavior
Pointer cast → returns nullptr if invalid
Reference cast → throws std::bad_cast */

/* ----------------------- -------------------------------------------- */
/* static_cast is resolved entirely at compile time.

✔️ What it can do
Upcast: Derived* → Base* (always safe)
Downcast: Base* → Derived* (NOT checked!)
Numeric conversions: int → float, etc.
Remove void* ambiguity

✔️ What it cannot do
It cannot check if the cast is valid at runtime
It cannot detect wrong downcasts */

/* ----------------------- -------------------------------------------- */
/* reinterpret_cast performs a raw bit‑level reinterpretation of memory.  
It does not check safety, does not convert types, and can easily cause undefined behavior. */