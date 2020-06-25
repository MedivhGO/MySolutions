//https://www.hackerrank.com/challenges/c-class-templates/problem
/*Write the class AddElements here*/
template <class T>
class AddElements
{
  private:
    T t;
  public:
    AddElements(T a):t(a) {}

    T add(T a) {
        return t+a;
    }

    T concatenate(T a) {
        return t+a;
    }
};