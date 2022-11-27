#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Test {
private:
	int data;
public:
	Test() : data{ 0 } {
		cout << "Test constructor " << data << endl;
	}
	Test(int v) : data{ v } {
		cout << "Test constructor " << data << endl;
	}
	int get_data() const { return data; }

	~Test() { cout << "Test destructor " << data << endl; }

};

//Function prototypes
unique_ptr<vector<shared_ptr<Test>>> make();
void fill(vector<shared_ptr<Test>> &v, int n);
void display(const vector<shared_ptr<Test>> &v);

int main() {
	/*Test* a = new Test();
	Test b = Test( 3 );
	delete a;*/

	unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();

	cout << "How many data points do you want to enter:" << endl;
	int num;
	cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);

	return 0;
}

unique_ptr<vector<shared_ptr<Test>>> make() {

	return make_unique<vector<shared_ptr<Test>>> ();
};

void fill(vector<shared_ptr<Test>>& v, int n) {
	int data;
	for (int i = 0;i < n;i++) {
		cout << "Enter data point [" << i << "]:";
		cin >> data;
		v.push_back(make_shared<Test>(data));
	}
		
};

void display(const vector<shared_ptr<Test>> &v) {
	cout << "Display vector data" << endl;
	for (auto elem : v)
		cout << elem->get_data() << endl;
};