#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v)
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto& e : v) {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}

void display_sizes(char const* comment,
                   const std::vector<std::string>& str_vec1,
                   const std::vector<std::string>& str_vec2,
                   const std::vector<std::string>& str_vec3)
{
    std::cout << comment
              << " size of string vector 1: " << str_vec1.size() << ','
              << " size of string vector 2: " << str_vec2.size() << ','
              << " size of string vector 3: " << str_vec3.size() << '\n';
}

void display(char const* comment, const std::vector<std::string>& v)
{
    std::cout << comment << "{ ";
    for (std::string e : v) {
        std::cout << e << ' ';
    }
    std::cout << "}\n";
}

int main(int argc, char **argv)
{
    // 构造函数
    // 默认构造函数
    std::vector<std::string> _default;
    // 构造拥有count（5）个值value（“chzha”）的容器（缺省构造空）
    std::vector<std::string> _count1(5);
    std::cout<<_count1<<std::endl;
    std::vector<std::string> _count2(5, "chzha");
    std::cout<<_count2<<std::endl;
    // 初始化列表语法
    std::vector<std::string> _str_vec1{"chzha", "is", "a", "handsome", "man"};
    std::cout<<_str_vec1<<std::endl;
    // 复制拷贝构造函数
    std::vector<std::string> _copy(_str_vec1);
    std::cout<<_copy<<std::endl;
    // 迭代器构造
    std::vector<std::string> _iter(_str_vec1.begin(), _str_vec1.end());
    std::cout<<_iter<<std::endl;

    // 复制赋值与移动赋值
    std::vector<std::string> _str_vec2;
    std::vector<std::string> _str_vec3;
    display_sizes("Initially:", _str_vec1, _str_vec2, _str_vec3);

    // 将_str_vec1复制赋值数据到_str_vec2
    _str_vec2 = _str_vec1;
    display_sizes("After assigment:", _str_vec1, _str_vec2, _str_vec3);

    // 将_str_vec1移动赋值到_str_vec3
    _str_vec3 = std::move(_str_vec1);
    display_sizes("After move assigment:", _str_vec1, _str_vec2, _str_vec3);
    display("Now string vector 3: ", _str_vec3);

    // initializer_list 的复制赋值复制数据给_str_vec3
    _str_vec3 = {"chzha", "is", "a", "good", "engineer"};
    display("After assignment of initializer_list, string vector 3: ", _str_vec3);

    // assign
    std::vector<std::string> _assign;
    std::vector<std::string> _assign_iter;
    std::vector<std::string> _assign_list;
    _assign.assign(5, "chzha");
    display("Assign: ", _assign);

    _assign_iter.assign(_assign.begin(), _assign.begin() + 3);
    display("Assgin (first to third): ", _assign_iter);
    _assign_iter.assign(_assign_iter.begin(), _assign_iter.begin() + 1);
    display("Assgin myself: ", _assign_iter);

    _assign_list.assign({"chzha", "is", "a", "good", "engineer"});
    display("Assgin list: ", _assign_list);

    // at
    _assign_list.at(4) = "boy";
    display("Assgin list after `at()`: ", _assign_list);
    std::cout<<"_assign_list at index 2 has value: "<<_assign_list.at(2)<<std::endl;
    try {
        _assign_list.at(5) = "!";
    } catch (std::out_of_range const& exc) {
        std::cout<<exc.what()<<std::endl;
    }

    // operator[]
    _assign_list[4] = "engineer";
    display("Assgin list after `[]`: ", _assign_list);
    // 会段错误(行为未定义)
    //_assign_list[5] = "boy";

    // front()
    std::string s = _assign_list.front();
    std::cout<<"The first string of '_assign_list': "<<s<<std::endl;
    // 会段错误(行为未定义)
    //std::cout<<_default.front()<<std::endl;

    // back()
    s = _assign_list.back();
    std::cout<<"The last string of '_assign_list': "<<s<<std::endl;

    // data()
    std::string *data = _assign_list.data();
    for (int i = 0; i < _assign_list.size(); ++i) {
        std::cout<<*(data + i)<<" ";
    }
    std::cout<<std::endl;
    data = _default.data();
    std::cout<<data<<std::endl;

    // 迭代器
    // begin()、cbegin()
    std::vector<std::string>::iterator _begin = _assign_list.begin();
    std::cout<<"The first string of '_assign_list': "<<*_begin<<std::endl;
    std::vector<std::string>::const_iterator _cbegin = _assign_list.cbegin();
    std::cout<<"The first string of '_assign_list': "<<*_cbegin<<std::endl;

    // end()、cend()
    for (; _begin != _assign_list.end(); ++_begin) {
        std::cout<<*_begin<<" ";
    }
    std::cout<<std::endl;
    for (; _cbegin != _assign_list.cend(); ++_cbegin) {
        std::cout<<*_cbegin<<" ";
    }
    std::cout<<std::endl;

    // rbegin()、crbegin()
    std::vector<std::string>::reverse_iterator _rbegin = _assign_list.rbegin();
    std::cout<<"The last string of '_assign_list': "<<*_rbegin<<std::endl;
    std::vector<std::string>::const_reverse_iterator _crbegin = _assign_list.crbegin();
    std::cout<<"The last string of '_assign_list': "<<*_crbegin<<std::endl;

    // rend()、crend()
    for (; _rbegin != _assign_list.rend(); ++_rbegin) {
        std::cout<<*_rbegin<<" ";
    }
    std::cout<<std::endl;
    for (; _crbegin != _assign_list.crend(); ++_crbegin) {
        std::cout<<*_crbegin<<" ";
    }
    std::cout<<std::endl;

    return 0;
}