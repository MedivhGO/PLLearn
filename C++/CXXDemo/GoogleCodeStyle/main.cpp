摘自Google开源项目风格指南 - C++风格指南
1.#define保护
使用#define防止头文件被多重包含
#ifndef <PROJECT>_<PATH>_<FILE>_H_
#define <PROJECT>_<PATH>_<FILE>_H_
...
#endif // <PROJECT>_<PATH>_<FILE>_H_

举个栗子~：
#ifndef STDIO_H_
#define STDIO_H_

#include <stdio.h>

#endif //stdio.h

2.函数参数的顺序
定义函数时, 参数顺序依次为: 输入参数, 然后是输出参数。

3.在 #include 中插入空行,
以分割相关头文件, C 库, C++ 库, 其他库的.h 和本项目内的.h 是个好习惯。

举个栗子~：
#include "foo/public/fooserver.h" // 优先位置

#include <sys/types.h>
#include <unistd.h>
#include <hash_map>
#include <vector>

#include "base/basictypes.h"
#include "base/commandlineflags.h"
#include "foo/public/bar.h"

4.通用命名规则
(1)函数命名，变量命名，文件命名要有描述性；少用缩写。
尽可能给有描述性的命名，别心疼空间，毕竟让代码易于新读者理解很重要。
不要用只有项目开发者能理解的缩写，也不要通过砍掉几个字母来缩写单词。

举个栗子~：
int price_count_reader;    // 无缩写
int num_errors;            // “num” 本来就很常见
int num_dns_connections;   // 人人都知道 “DNS” 是啥

(2)类型名称的每个单词首字母均大写, 不包含下划线: MyExcitingClass, MyExcitingEnum.

举个栗子~：
// classes and structs
class UrlTable {
	...
		class UrlTableTester {
		...
			struct UrlTableProperties {
			...

				// typedefs
				typedef hash_map<UrlTableProperties *, string> PropertiesMap;

			// enums
			enum UrlTableErrors {
				...

				(3)变量名一律小写, 单词之间用下划线连接.
				类的成员变量以下划线结尾, 但结构体的就不用，
				如 : a_local_variable, a_struct_data_member, a_class_data_member_.

				(4)函数命名
				常规函数使用大小写混合, 取值和设值函数则要求与变量名匹配 : MyExcitingFunction(), MyExcitingMethod(), my_exciting_member_variable(), set_my_exciting_member_variable().

				举个栗子~：
				常规函数 :

			函数名的每个单词首字母大写, 没有下划线。

				如果您的某函数出错时就要直接 crash, 那么就在函数名加上 OrDie.但这函数本身必须集成在产品代码里，且平时也可能会出错。

				AddTableEntry()
				DeleteUrl()
				OpenFileOrDie()
				取值和设值函数:

			取值（Accessors）和设值（Mutators）函数要与存取的变量名匹配.这儿摘录一个类, num_entries_ 是该类的实例变量 :

			class MyClass {
			public:
				...
					int num_entries() const { return num_entries_; }
				void set_num_entries(int num_entries) { num_entries_ = num_entries; }

			private:
				int num_entries_;
			};
			其它非常短小的内联函数名也可以用小写字母, 例如.如果你在循环中调用这样的函数甚至都不用缓存其返回值, 小写命名就可以接受.


				(5)名字空间用小写字母命名, 并基于项目名称和目录结构: google_awesome_project.

				(6)枚举的命名应当和 常量 或 宏 一致 : kEnumName 或是 ENUM_NAME.


				5.注释
				使用 // 或 /* */, 统一就好.
				文件注释：在每一个文件开头加入版权公告, 然后是文件内容描述.
				每个类的定义都要附带一份注释, 描述类的功能和用法.
				函数声明处注释描述函数功能; 定义处描述函数实现.
				如：
				// Returns true if the table cannot hold any more entries.
				bool IsTableFull();


			6.格式
			(1)行长度:每一行代码字符数不超过 80.
				(2)返回类型和函数名在同一行, 参数也尽量放在同一行，如果放不下就对形参分行。

				ReturnType ClassName::ReallyLongFunctionName(Type par_name1, Type par_name2,
					Type par_name3) {
				DoSomething();
				...
			}

			ReturnType LongClassName::ReallyReallyReallyLongFunctionName(
				Type par_name1,  // 4 空格缩进
				Type par_name2,
				Type par_name3) {
				DoSomething();  // 2 空格缩进
				...
			}

			(3)条件语句：倾向于不在圆括号内使用空格.关键字 if 和 else 另起一行.
				所有情况下 if 和左圆括号间都有个空格.右圆括号和左大括号之间也要有个空格:
			if (condition) {
				圆括号里没空格紧邻。
					...  // 2 空格缩进。
			}
			else {  // else 与 if 的右括号同一行。
				...
			}

		warning:
			if (condition)     // 差 - IF 后面没空格。
				if (condition) {   // 差 - { 前面没空格。
					if (condition) {    // 变本加厉地差。

						如果语句中某个 if - else 分支使用了大括号的话, 其它分支也必须使用:
						// 不可以这样子 - IF 有大括号 ELSE 却没有。
						if (condition) {
							foo;
						}
						else
							bar;

						// 不可以这样子 - ELSE 有大括号 IF 却没有。
						if (condition)
							foo;
						else {
							bar;
						}

						(4)空循环体应使用 {} 或 continue, 而不是一个简单的分号.

							while (condition) {
								// 反复循环直到条件失效。
							}
						for (int i = 0; i < kSomeNumber; ++i) {}  // 可 - 空循环体。
						while (condition) continue;  // 可 - continue 表明没有逻辑。

						(5)句点或箭头前后不要有空格.指针 / 地址操作符(*, &) 之后不能有空格.
							下面是指针和引用表达式的正确使用范例:

						x = *p;
						p = &x;
						x = r.y;
						x = r->y;

						(6)在声明指针变量或参数时, 星号与类型或变量名紧挨都可以:
						// 好样的，空格前置。
						char *c;
						const string &str;

						// 好样的，空格后置。
						char* c;    // 但别忘了 "char* c, *d, *e, ...;"!
						const string& str;

						char * c;  // 差 - * 两边都有空格
						const string & str;  // 差 - & 两边都有空格。


						(7)如果一个布尔表达式超过 标准行宽, 断行方式要统一一下.如逻辑与(&&) 操作符总位于行尾:
						if (this_one_thing > this_other_thing &&
							a_third_thing == a_fourth_thing &&
							yet_another & last_one) {
							...
						}

						(8)预处理指令不要缩进, 从行首开始.即使预处理指令位于缩进代码块中, 指令也应从行首开始.
							// 可 - directives at beginning of line
							if (lopsided_score) {
#if DISASTER_PENDING      // 正确 -- 行开头起。
								DropEverything();
#endif
								BackToNormal();
							}

						(9)类格式：访问控制块的声明依次序是 public:, protected:, private:, 每次缩进 1 个空格.
							如：
							class MyClass : public OtherClass {
							public:      // 注意有 1 空格缩进!
								MyClass();  // 照常，2 空格缩进。
								explicit MyClass(int var);
								~MyClass() {}

								void SomeFunction();
								void SomeFunctionThatDoesNothing() {
								}

								void set_some_var(int var) { some_var_ = var; }
								int some_var() const { return some_var_; }

							private:
								bool SomeInternalFunction();

								int some_var_;
								int some_other_var_;
								DISALLOW_COPY_AND_ASSIGN(MyClass);
						};

						(10)名字空间内容不缩进.
							名字空间 不要增加额外的缩进层次, 例如:

						namespace {

							void foo() {  // 正确。命名空间内没有额外的缩进。
								...
							}

						}  // namespace

						(11)循环和条件语句:

						if (b) {          // if 条件语句和循环语句关键字后均有空格。
						}
						else {          // else 前后有空格。
						}
						while (test) {}   // 圆括号内部不紧邻空格。
						switch (i) {
							for (int i = 0; i < 5; ++i) {
								switch (i) {    // 循环和条件语句的圆括号里可以与空格紧邻。
									if (test) {     // 圆括号，但这很少见。总之要一致。
										for (int i = 0; i < 5; ++i) {
											for (; i < 5; ++i) {  // 循环里内 ; 后恒有空格，； 前可以加个空格。
												switch (i) {
												case 1:         // switch case 的冒号前无空格。
													...
												case 2: break;// 如果冒号有代码，加个空格。
												}
												for (int i = 0; i < kSomeNumber; ++i)// 循环里内 ; 后恒有空格
													printf("I love you\n");

												(12)
													return; 比 return; 更约定俗成
													（事实上 cpplint 会对后者报错，指出分号前有多余的空格），且可用来提前跳出函数栈。


													事实上，如果您熟悉英语本身的书写规则，就会发现该风格指南在格式上的规定与英语语法相当一脉相承。比如普通标点符号和单词后面还有文本的话，总会留一个空格；特殊符号与单词之间就不用留了，比如 if (true) 中的圆括号与 true.

