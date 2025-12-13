# note

## 1.重载运算符

```c++
返回类型 operator运算符号(参数){
    实现
}
```

### 1.1隐式指针this/other

```c++
class Example {
    int data;
public:
    // 非const成员函数
    void modify() {
        this->data = 10;      // ✅ 可以修改成员
        // this = nullptr;    // ❌ 错误！this指针是const
    }
    
    // const成员函数
    void read() const {
        // this->data = 10;   // ❌ 错误！const成员函数中this指向const对象
        int x = this->data;   // ✅ 可以读取
    }
};
```

> 用于解决名称冲突,以及返回当前对象的引用,或传递当前对象

### 1.2左值/右值

```c++
int x = 10;

// 左值 (lvalue) - 有名字、有地址的表达式
int& lref = x;          // ✅ x 是左值
// int& lref2 = 10;     // ❌ 10 是右值，不能绑定到左值引用

// 右值 (rvalue) - 临时对象、字面量、将亡值
int&& rref = 10;        // ✅ 10 是右值，可以绑定到右值引用
int&& rref2 = x + 5;    // ✅ 表达式结果是临时值（右值）
// int&& rref3 = x;     // ❌ x 是左值，不能直接绑定到右值引用
```

> `std::move(变量名)`可以将左值转换为右值
> 基于&&的移动构造函数的效率比复制构造函数高,且更节约内存
