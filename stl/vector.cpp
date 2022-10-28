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
    std::vector<std::string> _list{"chzha", "is", "a", "handsome", "man"};
    std::cout<<_list<<std::endl;
    // 复制拷贝构造函数
    std::vector<std::string> _copy(_list);
    std::cout<<_copy<<std::endl;
    // 迭代器构造
    std::vector<std::string> _iter(_list.begin(), _list.end());
    std::cout<<_iter<<std::endl;

    return 0;
}