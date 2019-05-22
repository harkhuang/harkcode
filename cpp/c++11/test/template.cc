


/*
 * Variadic Template
 *
 * A template that can take any number of template arguments of any type.
 * Both class and function templates can be variadic.
 */
template<typename... arg>
class BoTemplate;

BoTemplate<float> t1;
BoTemplate<int, long, double, float> t2;
BoTemplate<int, std::vector<double>> t3;

BoTemplate<> t4;


// Combination of variadic and non-variadic argument
template<typename T, typename... arg>
class BoTemplate;

BoTemplate<> t4;  // Error
BoTemplate<int, long, double, float> t2;  // OK


// Define a default template argument
template<typename T = int, typename... arg>
class BoTemplate;




/*
 * Template Alias
 */
  template<class T> class Dog { /* ... */ };
  template<class T>
    using DogVec = std::vector<T, Dog<T>>;

  DogVec<int> v;  // Same as: std::vector<int, Dog<int>>


/*
 * extern template
 */
