# Теоретични въпроси

За следващите задачи ще използваме
```c++
class A
{
public:
	A()
	{
		std::cout << "A()" << std::endl;
	}

	A(const A& other)
	{
		std::cout << "C.C A()" << std::endl;
	}

    A(A&& other) noexcept {
        std::cout << "M.C A()" << std::endl;
    }

	A& operator=(const A& other)
	{
		std::cout << "OP= A()" << std::endl;
		return *this;
	}

    A& operator=(A&& other) noexcept {
        std::cout << "MOP= A()" << std::endl;
        return *this;
    }

	~A()
	{
		std::cout << "~A()" << std::endl;
	}
};
```
---
### 1. Какво ще се отпечата на конзолата
```c++
int main()
{
	std::vector<A> v(3);
	v.push_back(A());

	return 0;
}
```
---
### 2. Какво ще се отпечата на конзолата
```c++
struct B
{
	int val;

	B() : val(0) 
	{
		std::cout << "B()" << std::endl;
	}

	B(int val) : val(val) 
	{
		std::cout << "B(val)" << std::endl;
	}

	B& operator+=(const B& other)
	{
		std::cout << "B + B" << std::endl;
		val += other.val;
		return *this;
	}
};

B operator+(const B& lhs, const B& rhs)
{
	B temp = lhs;
	temp += rhs;
	return temp;
}

int main()
{
	B b1;
	B b2;

	b1 = 1 + 2;
	(b2 = 1) + 2;

	return 0;
}
```
---
### 3. Какво ще се отпечата на конзолата
```c++
class C
{
	A a;

public:
	C(A a) : a(std::move(a))
	{
		std::cout << "C()" << std::endl;
	}

	~C() 
	{
		std::cout << "~C()" << std::endl;
	}
};

int main()
{
	A a;
	C c(a);

	return 0;
}
```
---
### 4. Какво ще се отпечата на конзолата
```c++
class C
{
	A a;
	B b;

public:
	C(A a, B b) : b(b), a(a)
	{
		std::cout << "C()" << std::endl;
	}

	~C() 
	{
		std::cout << "~C()" << std::endl;
	}
};

int main()
{
	A a;
	B b;
	C c(a, b);

	return 0;
}
```
---
### 5. Какво ще се отпечата на конзолата
```c++
class C
{
	A a;
	B& b;

public:
	C(A& a, B b) : b(b)
	{
		this->a = a;
		std::cout << "C()" << std::endl;
	}

	~C() 
	{
		std::cout << "~C()" << std::endl;
	}
};

int main()
{
	A a;
	B b;
	C c(a, b);

	return 0;
}
```
---
### 6. Какво ще се отпечата на конзолата
```c++
class C
{
	A* a;
	B& b;

public:
	C(A& a, B& b) : b(b)
	{
		this->a = new A(a);
		std::cout << "C()" << std::endl;
	}

	~C() 
	{
		std::cout << "~C()" << std::endl;
	}
};

int main()
{
	A a;
	B b;
	C c(a, b);

	return 0;
}
```
---
### 7. Какво ще се отпечата на конзолата
```c++
class E {
	int* nums;

	void free() { delete[] nums; }
	void moveFrom(E&& other) { this->nums = other.nums; }

public:
	E() {
		std::cout << "E()" << std::endl;
		nums = new int(5);
	}

	E(E&& other) noexcept {
		std::cout << "M. C. E()" << std::endl;
		moveFrom(std::move(other));
	}

	E& operator=(E&& other) noexcept {
		std::cout << "MOP= E()" << std::endl;
		if (this != &other) {
			free();
			moveFrom(std::move(other));
		}

		return *this;
	}

	~E() {
		std::cout << "~E()" << std::endl;
		delete[] nums;
	}
};

E f() {
	return E();
}

int main() {
	E e1;
	e1 = f();

	return 0;
}
```
---
### 8. Какво ще се отпечата на конзолата
```c++
class X {
	char ch;

public:
	X() {
		ch = 'a';
		std::cout << "X()" << std::endl;
	}

	X(char ch) : ch(ch) {
		std::cout << "X(char)" << std::endl;
	}

	~X() {
		std::cout << "~X()" << std::endl;
	}
};

class Y{
public:

	Y() {
		std::cout << "Y()" << std::endl;
	}

	~Y() {
		std::cout << "~Y()" << std::endl;
	}
};

int main() {
	Y* ptr = new Y[2];
	X arr[3]{ 'a' };

	delete[] ptr;
	return 0;
}
```
---
### 9. Какво ще се отпечата на конзолата
```c++
A g()
{
	static int objectCount = 1;
	std::cout << objectCount++ << std::endl;
	A a;
	return a;
}

int main() {
	A a1 = g();
	A a2;
	a2 = g();

	return 0;
}
```
---
### 10. Какво ще се отпечата на конзолата
```c++
A process() {
	A a;
	return a;
}

int main() {
	A a = process();

	A a2;
	a2 = process();
}
```
---
### 11. Какво ще се отпечата на конзолата
```c++
A process(A a) {
	return a;
}

int main() {
	A a;

	A a2 = process(a);
}
```
---
### 12. Какво ще се отпечата на конзолата
```c++
A process(A a) {
	return a;
}

int main() {
	A a;

	A a2;
	a2 = process(a);
}
```
---
### 13. Какво ще се отпечата на конзолата
```c++
int main() {
	std::unique_ptr<A> p;
	std::cout << (p ? 1 : 0) << std::endl;
	{
		std::unique_ptr<A> q = std::make_unique<A>();
		p = std::move(q);
		std::cout << (q ? 1 : 0) << std::endl;
	}
	std::cout << (p ? 1 : 0) << std::endl;
}
```
---
### 14. Какво ще се отпечата на конзолата
```c++
class D {
	int num = 0;
public:
	D() : num(1) {}
	static int increment() {
		return num + 1;
	}
};

int main() {
	D::increment();
	D::increment();
	D::increment();
}
```
---
### 15. Какво ще се отпечата на конзолата
```c++
class Student {
	std::string name;

public:
	Student(std::string& name) : name(name) {}

	bool operator==(const std::string& name) {
		return this->name == name;
	}
};

int main() {
	std::string s = "Pesho";
	std::string t = std::move(s);

	Student student(s);
	std::cout << (student == t) << std::endl;
}
```
---
### 16. Какво ще се отпечата на конзолата
```c++
struct G
{
	void f() {
		std::cout << "f()" << std::endl;
	}

	void f() const {
		std::cout << "f() const" << std::endl;
	}

	void g() const {
		std::cout << "g()" << std::endl;
		f();
	}
};

void func(const G& obj) {
	obj.f();
	obj.g();
}

void func2(G obj) {
	obj.f();
	obj.g();
}

int main() {
	G g;
	g.f();

	func(g);
	func2(g);
}
```
---
### 17. Какво ще се отпечата на конзолата
```c++
struct MyPair {
	int key;
	char val;

	auto operator<=>(const MyPair& other) const = default;
};

int main() {
	MyPair p1(1, 'a');
	MyPair p2(2, 'c');
	MyPair p3(2, 'b');
	MyPair p4(2, 'b');

	std::cout << (p1 < p2) << " " << (p1 == p2) << std::endl;
	std::cout << (p2 < p3) << " " << (p2 == p3) << std::endl;
	std::cout << (p3 < p4) << " " << (p3 == p4) << std::endl;
}
```
---
### 18. Какво ще се отпечата на конзолата
```c++
int main() {
    std::shared_ptr<A> p1 = std::make_shared<A>();
    {
        std::shared_ptr<A> p2 = p1;
		std::shared_ptr<A> p3 = p1;
		std::shared_ptr<A> p4 = std::move(p3);
        std::cout << p1.use_count() << std::endl;
    }
    std::cout << p1.use_count() << std::endl;
}

```