#include<iostream>

using namespace std;

//节点结构体类
template <class T>
struct ListNode {
  ListNode(const T& value = T()) :_data(value) , _prev(nullptr), _next(nullptr) {}
  
	T _data;
	ListNode<T>* _prev;
	ListNode<T>* _next;
};


//迭代器类实现 - 可读可写
template <class T>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListIterator<T> Self;

	pNode _node;

	ListIterator(pNode node)
		:_node(node)
	{}

	//解引用： 可读可写
	T& operator*()
	{
		return _node->_data;
	}

	// ptr->_year; 可以可写
	T* operator->()
	{
		return &operator*();
		//return &_node->_data;
	}

	//迭代器前置++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	//迭代器后置加加
	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//!= 
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
		//return !*this != it;
	}
};

//迭代器类实现二  - 可读不可写
template <class T>
struct ListConstIterator
{
	typedef ListNode<T> Node;
	typedef ListNode<T>* pNode;
	typedef ListConstIterator<T> Self;

	pNode _node;

	ListConstIterator(pNode node)
		:_node(node)
	{}

	//解引用： 只读
	const T& operator*()
	{
		return _node->_data;
	}
	// ptr->_year; 只读
	const T* operator->()
	{
		return &operator*();
		//return &_node->_data;
	}

	//迭代器前置++
	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(*this);
		_node = _node->_next;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Self operator--(int)
	{
		Self tmp(*this);
		_node = _node->_prev;
		return tmp;
	}

	//!= 
	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	bool operator==(const Self& it)
	{
		return _node == it._node;
		//return !*this != it;
	}
};

//模拟实现List类
template<class T>
class List {
public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T> iterator;
	typedef ListConstIterator<T> const_iterator;

	//构造函数
	List() 
		:_Head(new Node)
	{
		//首先先要自环， 很关键
		_Head->_next = _Head;
		_Head->_prev = _Head;
	}

	//迭代器构造函数
	template<class Inputiterator>
	List(Inputiterator begin, Inputiterator end) 
		:_Head(new Node)
	{
		_Head->_next = _Head;
		_Head->_prev = _Head;

		while (begin != end) {
			Pushback(*begin);
			++begin;
		}
	}


	//构造函数  --  必须要深拷贝
	List(const List<T>& lst)
		:_Head(new Node)
	{
		_Head->_next = _Head;
		_Head->_prev = _Head;

		for (auto it : lst) {
			Pushback(it);		//Insert也可以
		}

	}

	//赋值运算符重载 - 现在写法
	List<T>& operator=(List<T>& lst) {
		swap(_Head, lst._Head);
		return *this;
	}
	
	//析构函数
	~List() {
		Clear();
		if (_Head) {
			delete _Head;
			_Head = nullptr;
		}
	}

	//尾插元素
	void Pushback(const T& val) {
		pNode prev_Node = _Head->_prev;		//得到尾节点
		pNode newNode = new Node(val);

		prev_Node->_next = newNode;
		newNode->_prev = prev_Node;
		newNode->_next = _Head;
		_Head->_prev = newNode;
		//下面是两种不同的写法， 代码复用
		//Insert(iterator(_Head), val);
		//INsert(end(), val);
	}

	//头插元素
	void PushFront(const T& val) {
		pNode next_Node = _Head->_next;
		pNode newNode = new Node(val);

		_Head->_next = newNode;
		newNode->_prev = _Head;
		newNode->_next = next_Node;
		next_Node->_prev = newNode;
		//Insert(iterator(_Head->_next), val);
		//Insert(begin(), val);
	}

	//头删
	void PopFront() {
		//方法实现和头插一样， 不重点写
		Erase(begin());
	}
	
	//尾删
	void Popback() {
		Erase(--end());
	}

	//任意位置插入 - 传入的迭代器和值
	void Insert(iterator pos, const T& val) {
		//在迭代器的位置插入  --  迭代器是一个类
		pNode node = pos._node;

		//先得到Node前面的节点
		pNode prev = node->_prev;

		pNode newNode = new Node(val);
		prev->_next = newNode;
		newNode->_prev = prev;
		newNode->_next = node;
		node->_prev = newNode;

	}

	//任意位置删除
	iterator Erase(iterator pos) {
		//在这块头节点_Head是不能删除的
		if (pos._node != _Head) {
			pNode node = pos._node;
			pNode prev = node->_prev;
			prev->_next = node->_next;
			node->_next->_prev = prev;
			++pos;
		}

		return pos;
	}
	
	//判空函数
	bool Empty() {
		if (_Head->_next == _Head)
			return true;
		else
			return false;
	}

	//清理函数
	void Clear() {
		if (!Empty()) {
			pNode cur = _Head->_next;
			while (cur != _Head) {
				pNode next = cur->_next;
				delete cur;
				cur = next;
			}

			//因此_Head不是在堆上开辟的， 因此不需要释放， 但是自环操作一定要有， 作为一些为空等一些接口的判断依据。
			_Head->_next = _Head;
			_Head->_prev = _Head;
		}

		//写法2
		//if (!Empty()) {
		//	iterator it = begin();
		//	while (it != end()) {
		//		Erase(it);
		//	}
		//}
	}
	
	//容器大小or长度
	size_t Size() {
		size_t count = 0;
		pNode tmp = _Head->_next;
		while(tmp != _Head)
		{
			++count;
			tmp = tmp->_next;
		}
		return count;
	}
	
	//下面是迭代器接口
	iterator begin() {
		return iterator(_Head->_next);
	}

	iterator end() {
		return iterator(_Head);
	}

	const_iterator begin() const {
		return const_iterator(_Head->_next);
	}

	const_iterator end() const {
		return const_iterator(_Head);
	}


private:
	pNode _Head;
};
