#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <iterator> // for std::advance
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>

class Person {
    friend std::ostream &operator<< (std::ostream &os, const Person &p);
    std::string name;
    int age;

    public:
    Person() : name{"Unknowm"}, age{0} {};                         
    Person(std::string name, int age)           // Constructor initialization list / Delegating constructor     
            :name{name}, age{age} {}

        bool operator< (const Person &rhs) const {          // overloaded less than operator - used for ordering
            // return this -> age < rhs.age;                   // this pointer - contains address of the object
            return this -> name < rhs.name;
        }

        bool operator== (const Person &rhs) const {         // overloaded equality operator
            return this->name == rhs.name && this->age == rhs.age;      
        }

};

std::ostream &operator<< (std::ostream &os, const Person &p) {
    os << p.name << " : " << p.age;
    return os;
}

void array () {
    // Initaialization  
    /* Array elements not initaialized contains garbage.
    If in intializer list    -> more element - error
                                -> fewer elements - remaining set to 0.                          
    */
    std::array<int, 5> arr {1, 2, 3, 4, 5};
    std::array<int, 5> arr1 {{10, 20, 30, 40, 50}};                 // In C++11
    std::array<std::string, 3> stooges {
        std::string{"Larry"},
        "Moe", 
        std::string{"Curly"}
    };

    // Assignment
    arr = {2, 4, 6, 8, 10};

    // Common methods
    std::cout << arr.size() << std::endl;
    std::cout << arr.at(0) << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr.front() << std::endl;
    std::cout << arr.back() << std:: endl;
    std::cout << arr.empty() << std:: endl;
    std::cout << arr.max_size() << std::endl;
    arr.swap(arr1);
    int *data = arr.data();
}

template <typename T>                               // template function
void display (const std::vector<T> &vec) {
    std::cout << "[ ";
    for(const auto &element : vec)                  // range based for loop
        std::cout << element << " ";
    std::cout << "]" << std::endl;
}

void vec () {
    // Declaration
    std::vector <int> vec (5);
    std::vector <Person> vec1;
    

    // Intialization
    std::vector <int> vec2 {1, 2, 3, 4, 5};
    std::vector <int> vec3 (10, 100);
    std::vector<std::string> stooges {
        std::string {"Larry"},
        "Moe",
        std::string {"Curly"}
    };

    // Assignment
    vec2 = {2, 4, 6, 8, 10};

    //Common methods
    std::cout << vec2.size() << std::endl;
    std::cout << vec2.capacity() << std::endl;
    std::cout << vec2.max_size() << std::endl;
    std::cout << vec2.at(0) << std::endl;
    std::cout << vec2[1] << std::endl;
    std::cout << vec2.front() << std::endl;
    std::cout << vec2.back() << std::endl;

    Person p1 {"Larry", 18};
    vec1.push_back(p1);
    vec1.pop_back();
    vec1.push_back(Person{"Larry", 18});
    vec1.emplace_back("Larry", 18);             // efficient

    std::cout << vec2.empty() << std::endl;
    vec2.swap(vec3);
    std::sort(vec2.begin(), vec2.end());
    auto it = std::find(vec2.begin(), vec2.end(), 4);
    vec3.insert(it, 10);
}

// template function to display any deque
template <typename T>
void display (const std::deque<T> &d) {
    std::cout << "[";
    for (const auto &elem: d)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void deque () {

    // Declaration
    std::deque <int> d;
    std::deque<Person> dp;

    // Initialization 
    std::deque <int> d1 {1, 2, 3, 4, 5};
    display(d1);
    std::deque <int> d2 (10, 100);
    display(d2);
    std::deque<std::string> stooges {
        std::string {"Larry"},
        "Moe",
        std::string{"Curly"},
    };
    
    // Assignment
    d1 = {2, 4, 5, 6};
    display(d1);

    // Subscript operator []
    d1[0] = 100;

    // Common methods
    d1.at(1) = 200;
    display(d1);

    std::cout << "Front: " << d1.front() << std::endl;
    std::cout << "Back: " << d1.back() << std::endl;
    std::cout << "Size: " << d1.size() << std::endl;
    std::cout << "Max Size: " << d1.max_size() << std::endl;

    d1.pop_back();
    display(d);
    d1.pop_front();
    display(d);

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (const auto &elem:vec) {
        if(elem%2 == 0)
            d.push_back(elem);
        else
            d.push_front(elem);
    }
    display(d);

    d.clear();

    for (const auto &elem: vec) 
        d.push_front(elem);
    display(d);

    d.clear();

    for(const auto &elem: vec) 
        d.push_back(elem);
    display(d);

    d.clear();

    std::copy(vec.begin(), vec.end(), front_inserter(d));
    display(d);

    d.clear();

    std::copy(vec.begin(), vec.end(), back_inserter(d));
    display(d);

    Person p1 {"Larry", 18};
    dp.push_back(p1);
    dp.push_front(Person{"Moe", 20});
    dp.emplace_back("Curly", 19);
    dp.emplace_front("Frank", 24);
    display(dp);  
}

template <typename T>
void display(const std::list<T> &l) {
    std::cout << "[";
    for (const auto &elem: l) 
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void list() {

    // Declaration
    std::list<std::string> l1;
    std::list<int> l2;
    std::list<Person> persons;

    // Intialization
    std::list<int> l3 {1, 2, 3, 4, 5, 6, 7};
    std::list<int> l4 (10, 100);
    display(l4);
    std::list<std::string> stooges {
        std::string {"Larry"},
        "Moe",
        std::string{"Curly"}
    };
    std::list<Person> l {
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}
    };
    
    // Assignment
    l2 = {1,2,3,4,5,6,7,8,9,10};
    l4 = {1000, 2000, 3000};
    
    // Subscript operator [] and .at() method are not available

    // Common methods

    l1.push_back("Back");
    l1.push_front("Front");
    display(l1);

    display(l2);
    std::cout << "Size: " << l3.size() << std::endl;
    std::cout << "Max Size: " << l3.size() << std::endl;
    std::cout << "Front: " << l3.front() << std::endl;
    std::cout << "Back: " << l3.back() << std::endl;

    l3.resize(5);
    display(l3);

    l3.resize(10);
    display(l3);

    l3.clear();
    display(l3);

    persons.resize(5);
    display(persons);

    auto it = std::find(l2.begin(), l2.end(), 5);
    std::cout << *it << std::endl;
    if(it != l2.end())
        l2.insert(it, 100);
    display(l2);

    std::cout << *it << std::endl;   // point to 5 

    l2.insert(it, l4.begin(), l4.end());
    display(l2);

    std::advance(it, -4);           // point to 100
    std::cout << *it << std::endl;
    it++;
    std::cout << *it << std::endl;
    it--;
    std::cout << *it << std::endl;

    l2.erase(it);                   // remove the 100 - iterator becomes invalid
    display(l2);

    display(l);
    Person p1 {"Tim", 28};
    l.push_back(p1);
    l.pop_back();

    l.push_front(Person{"Frank", 18});
    l.pop_front();

    l.emplace_back("Tim", 27);
    l.emplace_front("Frank", 24);

    std::string name;
    int age{};
    std::cout << "\nEnter the name of the next stooge: ";
    getline(std::cin, name);
    std::cout << "Enter their age: ";
    std::cin >> age;

    l.emplace_back(name, age);
    display(l);

    auto it1 = std::find(l.begin(), l.end(), Person{"Moe", 25});
    if(it1 != l.end())
        l.emplace(it1, "Angela", 20);
    display(l);

    l.sort();               // Use overloaded operator<
    display(l);

}

void forward_list() {

    // Declaration
    std::forward_list<Person> l;

    // Initialization
    std::forward_list<int> l1 {1,2,3,4,5};
    
    // Common methods
    /* std::cout << l.size();                  - not available */ 
    std::cout << "Max Size: " << l1.front() << std::endl;
    std::cout << "Front: " << l1.front() << std::endl;
    /* std::cout << l.back();                  - not available */ 

    Person p1 {"Larry", 18};
    l.push_front(p1);
    l.pop_front();
    l.emplace_front("Moe", 24);

    auto it = std::find(l1.begin(), l1.end(), 3);
    l1.insert_after(it, 10);
    l1.emplace_after(it, 100);

    l1.resize(2);
    l1.resize(5);

}

template <typename T>
void display(const std::set<T> &s) {
    std::cout << "[";
    for (const auto &elem: s) 
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void set () {

    // Initialization
    std::set<int> s1 {1, 4, 3, 5, 2};
    display(s1);
    std::set<Person> stooges {
        {"Larry", 1},
        {"Moe", 2},
        {"Curly", 3}
    };
    display(stooges);               // Note the order of display! operator<
    std::set<std::string> s {"A", "B", "C"};
    display(s);

    // Assignment
    s1 = {1,2,3,1,1,2,2,3,3,4,5};
    display(s1);

    s1.insert(0);
    s1.insert(10);
    display(s1);

    if(s1.count(10))
        std::cout << "10 is in the set" << std::endl;
    else
        std::cout << "10 is NOT in the set" << std::endl;

    auto it = s1.find(5);
    if (it != s1.end())
        std::cout << "Found: " << *it << std::endl;

    s1.clear();
    display(s1);

    stooges.emplace("James", 50);
    display(stooges);
    stooges.emplace("Frank", 50);           // NO -- 50 already exists
    display(stooges);

    auto it1 = stooges.find(Person{"Moe", 2});
    if(it1 != stooges.end())
        stooges.erase(it1);
    display(stooges);

    it1 = stooges.find(Person("XXX", 50));          // Will remove James!!!!  Uses operator<
    if(it1 != stooges.end())
        stooges.erase(it1);
    display(stooges);

    auto result = s.insert("D");
    display(s);

    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;
    std::cout << std::endl;

    result = s.insert("A");
    display(s);

    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;

}

template <typename T>
void display (std::stack<T> s) {                    // destructive process so we're passing stack by value (making a copy)
    std::cout << "[ ";
    while(!s.empty()) {
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << " ]" << std::endl;
}

void stack () {

    // Initialization
    std::stack <int> s;                  // deque - by default
    std::stack <int, std::vector<int>> s1;               // vector
    std::stack <int, std::list<int>> s2;                 // list
    std::stack <int, std::deque<int>> s3;                // deque                 
    
    // Common methods
    for(int i : {1, 2, 3, 4, 5})
        s.push(i);
    display(s);

    s.push(100);
    display(s);
    
    s.pop();
    s.pop();
    display(s);

    while(!s.empty())
        s.pop();
    display(s);

    std::cout << "Size: " << s.size() << std::endl;

    s.push(10);
    display(s);

    s.top() = 100;                               // top returns reference to the element at the top.
    display(s);

    std::cout << s.top();              

}
// stacks are used a lot in compiling

template <typename T>
void display(std::queue<T> q) {                 // passing by value (copy of the value is passed in) because passing reference to real queue will distroy it.
    std::cout << "[ ";
    while(!q.empty()) {
        T elem = q.front();
        q.pop();
        std::cout << elem << " ";
    }
    std::cout << " ]" << std::endl;
}



void queue () {

    // initialization
    std::queue<int> q;                  // deque
    std::queue<int, std::list<int>> q2;             //list
    std::queue<int, std::deque<int>> q3;            // deque

    // Commom methods
    for (int i : {1,2,3,4,5})
        q.push(i);
    display(q);
    
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while(!q.empty())
        q.pop();
    display(q);

    std::cout << "Size: " << q.size() << std::endl;

    q.push(10);
    q.push(100);
    q.push(1000);
    display(q);

    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    // front and back method return refernces so we can change the front and back method

    q.front() = 5;
    q.back() = 5000;

    display(q);
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

}

template <typename T>
void display(std::priority_queue<T> pq) {
    std::cout << "[ ";
    while(!pq.empty()) {
        T elem = pq.top();
        pq.pop();
        std::cout << elem << " ";
    }
    std::cout << " ]" << std::endl;
}

void priority_queue () {

    // Initialization
    std::priority_queue<int> pq;                // vector
    std::priority_queue<Person> pq1;
    // behind the scenes it's ordering, so it's using a heap data structure

    // Common methods
    for(int i:{3,5,7,12,23,12,4,100,0,3,5,7})
        pq.push(i);

    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;                      // largest element at the top
    
    display(pq);

    pq.pop();
    display(pq);

    pq1.push(Person{"A", 10});
    pq1.push(Person{"B",1});
    pq1.push(Person{"C", 14});
    pq1.push(Person{"D",18});
    pq1.push(Person{"E", 7});
    pq1.push(Person{"F",27});

    display(pq1);

}

// queues are used for scheduling job/task and operating systems

int main () {



    // deque();
    // list();
    // forward_list();
    set();

    // stack();
    // queue();
    // priority_queue();

    return 0;
}