#include <iostream>
using namespace std;

class shallow {
  private:
    int* data;
    
public:
  shallow(int d);
  shallow(const shallow &source);
  ~shallow();
  void set_data_value(int d) {*data = d;}
  int get_data_value() {return *data;}
    
};

shallow::shallow(int d) {
    data = new int;  // allocate storage
    *data = d;
}

shallow::~shallow() {
    delete data;
}

shallow::shallow(const shallow &source):data(source.data) {
    cout << "shallow copy" << endl;
}

void display_shallow(shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {
    shallow obj1 {100};
    display_shallow(obj1);
    
    shallow obj2 {obj1};
    obj2.set_data_value(1000);
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

class deep {
  private:
    int* data;
    
public:
  deep(int d);
  deep(const deep &source);
  ~deep();
  void set_data_value(int d) {*data = d;}
  int get_data_value() {return *data;}
    
};

deep::deep(int d) {
    data = new int;
    *data = d;  //stores the passed in integer d into where that data pointer is pointing
}

deep::~deep() {
    delete data;
    cout << "destructor freeing memory" << endl;
}

//deep::deep(const deep &source) {
//    data = new int;                                    // deep copy method 1 
//    *data = *source.data;
//    
//}

deep::deep(const deep &source):deep{*source.data} {      // deep copy method 2
    cout << "deep copy - delegation" <<endl;
}

void display_deep(deep s) {
    cout<< s.get_data_value() << endl;
}

int main() {
    deep obj1 {100};
    display_deep(obj1);
    
    deep obj2 {obj1};
    obj2.set_data_value(1000);
    return 0;
}
