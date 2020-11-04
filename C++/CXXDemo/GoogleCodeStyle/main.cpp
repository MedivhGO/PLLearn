ժ��Google��Դ��Ŀ���ָ�� - C++���ָ��
1.#define����
ʹ��#define��ֹͷ�ļ������ذ���
#ifndef <PROJECT>_<PATH>_<FILE>_H_
#define <PROJECT>_<PATH>_<FILE>_H_
...
#endif // <PROJECT>_<PATH>_<FILE>_H_

�ٸ�����~��
#ifndef STDIO_H_
#define STDIO_H_

#include <stdio.h>

#endif //stdio.h

2.����������˳��
���庯��ʱ, ����˳������Ϊ: �������, Ȼ�������������

3.�� #include �в������,
�Էָ����ͷ�ļ�, C ��, C++ ��, �������.h �ͱ���Ŀ�ڵ�.h �Ǹ���ϰ�ߡ�

�ٸ�����~��
#include "foo/public/fooserver.h" // ����λ��

#include <sys/types.h>
#include <unistd.h>
#include <hash_map>
#include <vector>

#include "base/basictypes.h"
#include "base/commandlineflags.h"
#include "foo/public/bar.h"

4.ͨ����������
(1)���������������������ļ�����Ҫ�������ԣ�������д��
�����ܸ��������Ե������������ۿռ䣬�Ͼ��ô��������¶���������Ҫ��
��Ҫ��ֻ����Ŀ��������������д��Ҳ��Ҫͨ������������ĸ����д���ʡ�

�ٸ�����~��
int price_count_reader;    // ����д
int num_errors;            // ��num�� �����ͺܳ���
int num_dns_connections;   // ���˶�֪�� ��DNS�� ��ɶ

(2)�������Ƶ�ÿ����������ĸ����д, �������»���: MyExcitingClass, MyExcitingEnum.

�ٸ�����~��
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

				(3)������һ��Сд, ����֮�����»�������.
				��ĳ�Ա�������»��߽�β, ���ṹ��ľͲ��ã�
				�� : a_local_variable, a_struct_data_member, a_class_data_member_.

				(4)��������
				���溯��ʹ�ô�Сд���, ȡֵ����ֵ������Ҫ���������ƥ�� : MyExcitingFunction(), MyExcitingMethod(), my_exciting_member_variable(), set_my_exciting_member_variable().

				�ٸ�����~��
				���溯�� :

			��������ÿ����������ĸ��д, û���»��ߡ�

				�������ĳ��������ʱ��Ҫֱ�� crash, ��ô���ں��������� OrDie.���⺯��������뼯���ڲ�Ʒ�������ƽʱҲ���ܻ����

				AddTableEntry()
				DeleteUrl()
				OpenFileOrDie()
				ȡֵ����ֵ����:

			ȡֵ��Accessors������ֵ��Mutators������Ҫ���ȡ�ı�����ƥ��.���ժ¼һ����, num_entries_ �Ǹ����ʵ������ :

			class MyClass {
			public:
				...
					int num_entries() const { return num_entries_; }
				void set_num_entries(int num_entries) { num_entries_ = num_entries; }

			private:
				int num_entries_;
			};
			�����ǳ���С������������Ҳ������Сд��ĸ, ����.�������ѭ���е��������ĺ������������û����䷵��ֵ, Сд�����Ϳ��Խ���.


				(5)���ֿռ���Сд��ĸ����, ��������Ŀ���ƺ�Ŀ¼�ṹ: google_awesome_project.

				(6)ö�ٵ�����Ӧ���� ���� �� �� һ�� : kEnumName ���� ENUM_NAME.


				5.ע��
				ʹ�� // �� /* */, ͳһ�ͺ�.
				�ļ�ע�ͣ���ÿһ���ļ���ͷ�����Ȩ����, Ȼ�����ļ���������.
				ÿ����Ķ��嶼Ҫ����һ��ע��, ������Ĺ��ܺ��÷�.
				����������ע��������������; ���崦��������ʵ��.
				�磺
				// Returns true if the table cannot hold any more entries.
				bool IsTableFull();


			6.��ʽ
			(1)�г���:ÿһ�д����ַ��������� 80.
				(2)�������ͺͺ�������ͬһ��, ����Ҳ��������ͬһ�У�����Ų��¾Ͷ��βη��С�

				ReturnType ClassName::ReallyLongFunctionName(Type par_name1, Type par_name2,
					Type par_name3) {
				DoSomething();
				...
			}

			ReturnType LongClassName::ReallyReallyReallyLongFunctionName(
				Type par_name1,  // 4 �ո�����
				Type par_name2,
				Type par_name3) {
				DoSomething();  // 2 �ո�����
				...
			}

			(3)������䣺�����ڲ���Բ������ʹ�ÿո�.�ؼ��� if �� else ����һ��.
				��������� if ����Բ���ż䶼�и��ո�.��Բ���ź��������֮��ҲҪ�и��ո�:
			if (condition) {
				Բ������û�ո���ڡ�
					...  // 2 �ո�������
			}
			else {  // else �� if ��������ͬһ�С�
				...
			}

		warning:
			if (condition)     // �� - IF ����û�ո�
				if (condition) {   // �� - { ǰ��û�ո�
					if (condition) {    // �䱾�����ز

						��������ĳ�� if - else ��֧ʹ���˴����ŵĻ�, ������֧Ҳ����ʹ��:
						// ������������ - IF �д����� ELSE ȴû�С�
						if (condition) {
							foo;
						}
						else
							bar;

						// ������������ - ELSE �д����� IF ȴû�С�
						if (condition)
							foo;
						else {
							bar;
						}

						(4)��ѭ����Ӧʹ�� {} �� continue, ������һ���򵥵ķֺ�.

							while (condition) {
								// ����ѭ��ֱ������ʧЧ��
							}
						for (int i = 0; i < kSomeNumber; ++i) {}  // �� - ��ѭ���塣
						while (condition) continue;  // �� - continue ����û���߼���

						(5)�����ͷǰ��Ҫ�пո�.ָ�� / ��ַ������(*, &) ֮�����пո�.
							������ָ������ñ��ʽ����ȷʹ�÷���:

						x = *p;
						p = &x;
						x = r.y;
						x = r->y;

						(6)������ָ����������ʱ, �Ǻ������ͻ����������������:
						// �����ģ��ո�ǰ�á�
						char *c;
						const string &str;

						// �����ģ��ո���á�
						char* c;    // �������� "char* c, *d, *e, ...;"!
						const string& str;

						char * c;  // �� - * ���߶��пո�
						const string & str;  // �� - & ���߶��пո�


						(7)���һ���������ʽ���� ��׼�п�, ���з�ʽҪͳһһ��.���߼���(&&) ��������λ����β:
						if (this_one_thing > this_other_thing &&
							a_third_thing == a_fourth_thing &&
							yet_another & last_one) {
							...
						}

						(8)Ԥ����ָ�Ҫ����, �����׿�ʼ.��ʹԤ����ָ��λ�������������, ָ��ҲӦ�����׿�ʼ.
							// �� - directives at beginning of line
							if (lopsided_score) {
#if DISASTER_PENDING      // ��ȷ -- �п�ͷ��
								DropEverything();
#endif
								BackToNormal();
							}

						(9)���ʽ�����ʿ��ƿ�������������� public:, protected:, private:, ÿ������ 1 ���ո�.
							�磺
							class MyClass : public OtherClass {
							public:      // ע���� 1 �ո�����!
								MyClass();  // �ճ���2 �ո�������
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

						(10)���ֿռ����ݲ�����.
							���ֿռ� ��Ҫ���Ӷ�����������, ����:

						namespace {

							void foo() {  // ��ȷ�������ռ���û�ж����������
								...
							}

						}  // namespace

						(11)ѭ�����������:

						if (b) {          // if ��������ѭ�����ؼ��ֺ���пո�
						}
						else {          // else ǰ���пո�
						}
						while (test) {}   // Բ�����ڲ������ڿո�
						switch (i) {
							for (int i = 0; i < 5; ++i) {
								switch (i) {    // ѭ������������Բ�����������ո���ڡ�
									if (test) {     // Բ���ţ�������ټ�����֮Ҫһ�¡�
										for (int i = 0; i < 5; ++i) {
											for (; i < 5; ++i) {  // ѭ������ ; ����пո񣬣� ǰ���ԼӸ��ո�
												switch (i) {
												case 1:         // switch case ��ð��ǰ�޿ո�
													...
												case 2: break;// ���ð���д��룬�Ӹ��ո�
												}
												for (int i = 0; i < kSomeNumber; ++i)// ѭ������ ; ����пո�
													printf("I love you\n");

												(12)
													return; �� return; ��Լ���׳�
													����ʵ�� cpplint ��Ժ��߱���ָ���ֺ�ǰ�ж���Ŀո񣩣��ҿ�������ǰ��������ջ��


													��ʵ�ϣ��������ϤӢ�ﱾ�����д���򣬾ͻᷢ�ָ÷��ָ���ڸ�ʽ�ϵĹ涨��Ӣ���﷨�൱һ����С�������ͨ�����ź͵��ʺ��滹���ı��Ļ����ܻ���һ���ո���������뵥��֮��Ͳ������ˣ����� if (true) �е�Բ������ true.

