libentity
=========

Entity is a C++11 library that provides object serialisation/deserialisation 
yet requires very little boilerplate code.

A simple [tree](https://github.com/emergent-design/libentity/wiki/Tree) 
structure lies at the heart of libentity which simplifies the implementation 
of string-based emitters/parsers. This tree structure can be used directly but 
the higher level [entity](https://github.com/emergent-design/libentity/wiki/Entity) 
mapping will allow you to augment your classes and structs in a much cleaner way.


Warning
-------

This library should be considered alpha and as such is not suitable for production 
environments. However, the API for the 
[entity](https://github.com/emergent-design/libentity/wiki/Entity) base class is 
extremely simple and therefore unlikely to change.


Parsers
-------

The [parsers](https://github.com/emergent-design/libentity/wiki/Parsers) implemented 
so far:

* JSON
* XML

The underlying value types match those used in JSON (string, number, boolean, 
array, object and null).


Mapped types
------------

<table>
	<tr><th>Type</th><th>Mapping</th><th>Limitation</tr>
	<tr><td>string</td><td>String</td><td></td></tr>
	<tr><td>float</td><td>Number</td><td></td></tr>
	<tr><td>double</td><td>Number</td><td></td></tr>
	<tr><td>int</td><td>Number</td><td></td></tr>
	<tr><td>long</td><td>Number</td><td></td></tr>
	<tr><td>bool</td><td>Boolean</td><td></td></tr>
	<tr><td>entity</td><td>Object</td><td>Any structure/class derived from entity</td></tr>
	<tr><td>std::vector&lt;T&gt;</td><td>Array</td><td>T must be a supported type listed here</td></tr>
	<tr><td>std::map&lt;string,T&gt;</td><td>Object</td><td>The dictionary key must be a string</td></tr>

	<tr><td></td><td></td><td></td></tr>
</table>


Example
-------

```cpp
#include <entity/entity.h>
#include <entity/json.h>

using namespace std;
using namespace ent;


// A structure with simple members that is derived from entity
struct Simple : entity
{
	string name	= "default";
	bool flag	= false;
	int integer = 0;

	void create_map()
	{
		map("name", this->name);
		map("flag", this->flag);
		map("integer", this->integer);
	}
};


const string JSON_TEXT = u8R"json(
	{
		"name":   "simple",
		"flag":    true,
		"integer": 42
	}
)json";


int main(int argc, char *argv[])
{
	Simple simple;

	// Serialise the simple object to JSON (will contain the default
	// values assigned above)
	cout << simple.to<json>() << endl;

	// Deserialise the simple object from a JSON string
	simple.from<json>(JSON_TEXT);

	// These values will now match those defined in JSON_TEXT
	cout << "Name    = " << simple.name << endl;
	cout << "Flag    = " << simple.flag << endl;
	cout << "Integer = " << simple.integer << endl;

	return 0;
}
```

If the above example was saved to "simple.cpp" then you would compile it as follows

```bash
g++ -std=c++11 simple.cpp -lentity
```

Any class or struct that descends from 
[entity](https://github.com/emergent-design/libentity/wiki/Entity) 
must implement the 
[create_map](https://github.com/emergent-design/libentity/wiki/Entity#create-map) 
function which allows the library to do its magic without the need for a 
pre-compilation step.


Installation
------------

There are no package archives available yet, but packages can be 
[downloaded](http://downloads.emergent-design.co.uk/libentity) which should work
on all recent debian-based 64-bit distributions.

If you require 32-bit libraries you must 
[build from source](https://github.com/emergent-design/libentity/wiki/Building-from-source) 
and, with some tweaking of the build process, it should also be possible to 
compile for Windows/OSX since it has no dependencies other than a modern compiler 
that supports C++11.
