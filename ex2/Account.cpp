#include "Account.h"
Account::Account():
	m_transactionList(nullptr),
	m_numberOfTransaction(0),
	m_persons(nullptr),
	m_totalPersons(0), 
	m_accountNumber(0),
	m_balance(0){}
Account::Account(Person** persons, int count, double balance) :
	m_transactionList(nullptr), 
	m_numberOfTransaction(0),
	m_persons(nullptr),
	m_totalPersons(count),
	m_balance(balance) {
	m_persons = new Person*[count];
	for (int i = 0; i < count; i++)
	{
		m_persons[i] = new Person(*persons[i]);
	}
	for (int i = 0; i < count; i++) {
		m_accountNumber = 0;
		m_accountNumber = m_persons[i]->GetId() + m_accountNumber;
	}
}
Account::Account(const Person& person, double balance) :
	m_transactionList(nullptr),
	m_numberOfTransaction(0),
	m_persons(nullptr),
	m_totalPersons(1),
	m_accountNumber(0),
	m_balance(balance)
{
	m_persons = new Person*[1];
	m_persons[0] = new Person(person);
	m_accountNumber = m_persons[0]->GetId();
}
Account::Account(const Account& other) :
	m_transactionList(nullptr),
	m_numberOfTransaction(other.m_numberOfTransaction),
	m_persons(nullptr),
	m_totalPersons(other.m_totalPersons),
	m_accountNumber(other.m_accountNumber),
	m_balance(other.m_balance)
{
	SetTransactions(other.m_transactionList, other.m_numberOfTransaction);
	SetPersons(other.m_persons, other.m_totalPersons);
}
Account::~Account() {
	clearTransactions();
	clearPersons();
}
void Account::SetPersons(Person** persons, int count) {
	clearPersons();
	m_totalPersons = count;
	m_persons = new Person * [m_totalPersons];
	for (int i = 0; i < m_totalPersons; i++)
	{
		m_persons[i] = new Person(*persons[i]);
	}
}
void Account::SetAccountNumber(int number) {
	m_accountNumber = number;
}
void Account::SetBalance(double balance) {
	m_balance = balance;
}
void Account::SetTransactions(Transaction** newTransaction, int count) {
	clearTransactions();
	m_numberOfTransaction = count;
	if(m_numberOfTransaction>0){
		m_transactionList = new Transaction * [m_numberOfTransaction];
		for (int i = 0; i < m_numberOfTransaction; i++) {
			m_transactionList[i] = new Transaction(*newTransaction[i]);
		}
	}
}
Transaction** Account::GetTransactions() {
	return m_transactionList;
}
int Account::GetNumOfTransactions() {
	return m_numberOfTransaction;
}
Person** Account::GetPersons() const{
	return m_persons;
}
int Account::GetTotalPersons() const {
	return m_totalPersons;
}
int Account::GetAccountNumber() const {
	return m_accountNumber;
}
double Account::GetBalance() const {
	return m_balance;
}
void Account::Withdraw(double amount, const char* date) {
	AddTransaction(Transaction(this, this, -amount, date));
}
void Account::Deposit(double amount, const char* date) {
	AddTransaction(Transaction(this, this, amount, date));
}
void Account::AddPerson(const Person& newPerson, double	amount) {
	m_balance = m_balance + amount;
	bool x = false; 
	for (int i = 0; i < m_totalPersons; i++) {
		if (m_persons[i]->GetId() == newPerson.GetId())
			x == true;
	}
	if (x == true) 
		return;
	if (m_totalPersons == 0 && m_persons == nullptr) {
		m_totalPersons = 1;
		m_persons = new Person * [1];
		m_persons[0] = new Person(newPerson);
	}
	else
	{
		Person** newtemp;
		newtemp = new Person * [m_totalPersons+1];
		for (int i = 0; i < m_totalPersons; i++) {
			newtemp[i] = m_persons[i];
		}
		newtemp[m_totalPersons] = new Person(newPerson);
		m_totalPersons = m_totalPersons + 1;
		delete m_persons;
		m_persons = newtemp;
	}
}
void Account::DeletePerson(const Person& oldPerson) {
	bool x = false;
	for (int i = 0; i < m_totalPersons; i++) {
		if (m_persons[i]->GetId() == oldPerson.GetId())
			x == true;
	}
	if (x == false)
		return;
	if (m_totalPersons == 1) {
		delete m_persons[0];
		m_persons = nullptr;
		m_totalPersons = 0;
	}
	else {
		int num;
		for (int i = 0; i < m_totalPersons; i++) {
			if (m_persons[i]->GetId() == oldPerson.GetId()) {
				delete m_persons[i];
				num = i;
				if (num == m_totalPersons - 1)
					return;
				else {
					for (int t = num + 1; t < m_totalPersons; t++)
						m_persons[t] = m_persons[t - 1];
				}
				i = m_totalPersons;
			}
		}
		m_totalPersons = m_totalPersons - 1;
	}
}
void Account::AddTransaction(const Transaction& newTransaction) {
	Account* src = newTransaction.GetSource();
	Account* dst = newTransaction.GetDes();
	if (src->GetAccountNumber() == dst->GetAccountNumber()) {
		if (src->GetNumOfTransactions() && src->GetTransactions() == nullptr)
		{
			src->m_numberOfTransaction++;
			src->m_transactionList = new Transaction * [1];
			src->m_transactionList[0] = new Transaction(newTransaction);
		}
		else
		{
			Transaction** temptran = new Transaction * [src->m_numberOfTransaction + 1];
			for (int i = 0; i < src->m_numberOfTransaction; ++i)
			{
				temptran[i] = src->m_transactionList[i];
			}
			temptran[src->m_numberOfTransaction] = new Transaction(newTransaction);
			delete[] src->m_transactionList;
			src->m_transactionList = temptran;
			++src->m_numberOfTransaction;
			src->m_balance = src->GetBalance() + newTransaction.GetAmount();
		}
	}
	else
	{
		if (src->GetNumOfTransactions() && src->GetTransactions() == nullptr)
		{
			src->m_numberOfTransaction++;
			src->m_transactionList = new Transaction * [1];
			src->m_transactionList[0] = new Transaction(newTransaction);
		}
		else
		{
			Transaction** temptran = new Transaction * [src->m_numberOfTransaction + 1];
			for (int i = 0; i < src->m_numberOfTransaction; ++i)
			{
				temptran[i] = src->m_transactionList[i];
			}
			temptran[src->m_numberOfTransaction] = new Transaction(newTransaction);
			delete[] src->m_transactionList;
			src->m_transactionList = temptran;
			++src->m_numberOfTransaction;
			src->m_balance = src->GetBalance() - newTransaction.GetAmount();
		}
		if (dst->GetNumOfTransactions() && dst->GetTransactions() == nullptr)
		{
			dst->m_numberOfTransaction++;
			dst->m_transactionList = new Transaction * [1];
			dst->m_transactionList[0] = new Transaction(newTransaction);
		}
		else
		{
			Transaction** temptran = new Transaction * [dst->m_numberOfTransaction + 1];
			for (int i = 0; i < dst->m_numberOfTransaction; ++i)
			{
				temptran[i] = dst->m_transactionList[i];
			}
			temptran[dst->m_numberOfTransaction] = new Transaction(newTransaction);
			delete[] dst->m_transactionList;
			dst->m_transactionList = temptran;
			++dst->m_numberOfTransaction;
			dst->m_balance = dst->GetBalance() + newTransaction.GetAmount();
		}
	}
}
void Account::clearTransactions()
{
	if (m_transactionList)
	{
		for (int i = 0; i < m_numberOfTransaction; i++)
			delete m_transactionList[i];

		delete[] m_transactionList;

		m_transactionList = nullptr;
	}
}
void Account::clearPersons(){
	if (m_persons)
	{
		for (int i = 0; i < m_totalPersons; i++)
			delete m_persons[i];

		delete[] m_persons;

		m_persons = nullptr;
	}
}

