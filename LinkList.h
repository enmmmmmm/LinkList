#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
class LinkList;


//  �����ࣺ��Node���ж�����Ԫ�ķ�ʽ��ʹList����Է��ʽ���˽�г�Ա
template <class T>
class LinkNode
{
	friend class LinkList<T>;
public:
	LinkNode(T x ) 
	{
		_data = x;
		_next = NULL;
	}


private:
	T _data;
	LinkNode<T>  *_next;
};
template <class T>
class LinkList
{
public:


LinkList()
{	
	_head = NULL;
}



void PushBack(const T& x);		//β��
void PopBack();		//βɾ

void PushFront(const T& x);
void PopFront();

int LinkList<T> ::Length();		//���
LinkNode<T>* Find(const T& x);

void Insert_pos(size_t pos, const T& x);
void Insert_val(const T& n, const T& x);
LinkNode <T> * Reverse();

void Delete_pos(size_t pos);
void Delete_val(const T& x);

void Print()							// ��ӡ
{
	LinkNode<T>  *tmp = _head;
	while (tmp != NULL)
	{
		cout << tmp->_data << "->";
		tmp = tmp->_next;
	}
	cout << "NULL" << endl;
}
public:

	LinkNode<T>* _CreateNode(const T& x)			//�������
	{
		LinkNode<T>* tmp = new LinkNode<T>(x);
		return tmp;
	}


	void clear(LinkNode<T>* &cur)
	{
		cur->_next = NULL;
		delete  cur;
		cur = NULL;
	}

private:
	LinkNode<T> * _head;
};

template<class T>
int LinkList<T> ::Length()				//���
{
	int len = 0;
	if (_head == NULL)
	{
		cout << "The Length of List is:" << "0" << endl;
		return 0;
	}
	else
	{
		LinkNode<T> * begin = _head;
		while (begin != NULL)
		{
			begin = begin->_next;
			len++;
		}
	}
	cout << "The Length of List is >>>:  " << len << endl;
	return len;
}

template <class T>
void LinkList<T> ::PushBack(const T& x)			//β��
{
	if (_head == NULL)
	{
		_head = _CreateNode(x);
	}
	else
	{
		LinkNode<T> * end = _head;
		while (end->_next != NULL)
		{
			end = end->_next;
		}
		end->_next = _CreateNode(x);
	}
}

template <class T>
void LinkList<T> :: PopBack()			//βɾ
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else if (_head->_next == NULL)
	{
		clear(_head);
	}
	else
	{
		LinkNode<T> * prev = _head;
		LinkNode<T> * end = _head;
		while (end->_next != NULL)
		{
			prev = end;
			end = end->_next;
		}
		prev->_next = NULL;
		clear(end);
	}
}

template <class T>
void LinkList<T> :: PushFront(const T& x)		//ͷ��
{
	if (_head == NULL)
	{
		_head = _CreateNode(x);
	}
	else
	{
		LinkNode<T>  * prev = _CreateNode(x);
		prev->_next = _head;
		_head = prev;
	}
}

template <class T>
void LinkList<T> ::PopFront()				
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else if (_head->_head == NULL)
	{
		clear(_head);
	}
	else
	{
		LinkNode<T> * tmp = _head;
		_head = _head->_next;
		clear(tmp);
		tmp = NULL;
	}
}


template <class T>
LinkNode<T>* LinkList<T> ::Find (const T& x)			//����
{
	if (_head == NULL)
	{
		cout << "List is empty,not found!!!" << endl;
		return NULL;
	}
	else
	{
		LinkNode<T> * n = _head ;
		while (n->_next != NULL && n->_data != x )
		{
			n = n->_next;
			if (n->_data == x)
			{
				cout << "The data of your find is :" << n->_data << endl;
				return n;
			}
		}
	}
	cout << "There is no this data in the List!!��" << endl;
	return NULL;
}


template <class T>
void LinkList<T> ::Insert_pos(size_t pos,const T& x)		//�ڵ�n���������
{
	int len = Length();
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else
		{
			LinkNode<T> * begin = _head;
			LinkNode<T> * tmp = _CreateNode(x);
			while (--pos)
			{
				if (begin->_next != NULL)
				{
					begin = begin->_next;
				}
			}
			tmp->_next = begin->_next;
			begin->_next = tmp;
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}



template <class T>
void LinkList<T> ::Insert_val(const T& m ,const T& x)			//��ֵ����
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else
	{
		LinkNode<T> * n =  Find(m);
		if (n != NULL)
		{
			LinkNode<T> * tmp = _CreateNode(x);
			tmp->_next = n->_next;
			n->_next = tmp;
		}
		cout << "Input Error!!!" << endl;
	}
}



template <class T>
void LinkList<T> ::Delete_pos(size_t pos)		//ɾ����n��
{
	int len = Length();
	if (pos <= len)
	{
		if (_head == NULL)
		{
			cout << "List is empty!!!" << endl;
			return;
		}
		else if (_head->_next == NULL)
		{
			clear(_head);
		}
		else
		{
			LinkNode<T> * begin = _head->_next;
			LinkNode<T> * tmp = _head;
			pos = pos - 1;
			while (--pos)
			{
				if (begin->_next != NULL)
				{
					begin = begin->_next;
					tmp = tmp->_next;
				}
			}
			tmp->_next = begin->_next;
			begin->_next = tmp;
		}
	}
	else
	{
		cout << "Input Error!!!" << endl;
	}
}


template <class T>
void LinkList<T> ::Delete_val(const T& x)			//��ֵɾ��
{
	if (_head == NULL)
	{
		cout << "List is empty!!!" << endl;
		return;
	}
	else if (_head->_next == NULL && _head->_data == x)
	{
		clear(_head);
		return;
	}
	else
	{
		if (_head->_data == x)
		{
			PopFront();
			return;
		}
		else
		{
			LinkNode<T> * n = Find(x);
			if (n != NULL)
			{
				LinkNode<T> * begin = _head;
				while (n != NULL && begin->_next != n && begin->_next != NULL)
				{
					begin = begin->_next;
				}
				begin->_next = n->_next;
				clear(n);
				return;
			}
		}
	}
	return;
}
template <class T>
LinkNode <T> * LinkList <T> ::Reverse()			// ����
{
	if (_head == NULL || _head->_next == NULL)//Ϊ��
	{
		return NULL;
	}
	else									//�ǿ�
	{
		LinkNode<T> * Newhead = _head;
		LinkNode<T> * begin = _head->_next;
		LinkNode<T> *tmp = NULL;
		_head->_next = NULL;
		while (begin != NULL)
		{
			tmp = begin;
			begin = begin->_next;
			
			tmp->_next = Newhead;
			Newhead = tmp;
		}
		_head = Newhead;
	}
}