#include "Bank.h"
Bank::Bank() :
	m_name(nullptr),
	m_account(nullptr),
	m_bankCode(0),
	m_numbeOfAccounts(0),
	m_totalBalance(0){}
Bank::Bank(const char* name, int code):
m_account(nullptr),
m_numbeOfAccounts(0),
m_totalBalance(0),
m_bankCode(code){
	SetBankName(name);
}
Bank::~Bank() {
	if (m_name)
		delete m_name;
	if (m_account)
	{
		for (int i = 0; i < m_numbeOfAccounts; i++)
			delete m_account[i];
		delete[] m_account;
	}
}
void Bank::SetBankName(const char* name) {
	if (m_name)
		delete m_name;
	m_name = _strdup(name);
}
void Bank::SetAccount(Account** account, int numbeOfAccounts) {
	if (m_account)
	{
		for (int i = 0; i < m_numbeOfAccounts; i++)
			delete m_account[i];
		delete[] m_account;
	}
	m_totalBalance = 0;
	m_numbeOfAccounts = numbeOfAccounts;
	for (int i = 0; i < m_numbeOfAccounts; i++)
	{
		m_account[i] = account[i];
		m_totalBalance = m_totalBalance + account[i]->GetBalance();
	}
}
void Bank::SetTotal(double total) {
	m_totalBalance = total;
}
void Bank::SetCode(int code) {
	m_bankCode = code;
}
const char* Bank::GetBankName() const {
	return m_name;
}
Account** Bank::GetAccounts() const {
	return m_account;
}
int Bank::GetNumberOfAccounts() const {
	return m_numbeOfAccounts;
}
double Bank::GetTotal() const {
	return m_totalBalance;
}
int Bank::GetCode() const {
	return m_bankCode;
}
void Bank::AddAccount(const Account& account) {
	for (int i = 0; i < m_numbeOfAccounts; i++)
	{
		if (m_account[i]->GetAccountNumber() == account.GetAccountNumber())
			return;
	}
	if (m_numbeOfAccounts == 0)
	{
		m_account = new Account * [1];
		m_account[0] = new Account(account);
		m_numbeOfAccounts = 1;
	}
	else
	{
		Account** tempacp = new Account * [m_numbeOfAccounts + 1];
		for (int i = 0; i < m_numbeOfAccounts; i++)
		{
			tempacp[i] = m_account[i];
		}
		tempacp[m_numbeOfAccounts] = new Account(account);
		delete[] m_account;
		m_numbeOfAccounts = m_numbeOfAccounts + 1;
		m_account = tempacp;
	}
	m_totalBalance += account.GetBalance();
}
void Bank::AddAccount(const Person& per, double amount) {
	Account* newaco = new Account(per, amount);
	this->AddAccount(*newaco);
}
void Bank::AddPerson(const Person& newPerson, const Account& account, double amount)
{
	for (int i = 0; i < m_numbeOfAccounts; ++i)
	{
		if (m_account[i]->GetAccountNumber() == account.GetAccountNumber())
		{
			int prevAmount = m_account[i]->GetTotalPersons();
			m_account[i]->AddPerson(newPerson, amount);
			if (prevAmount < m_account[i]->GetTotalPersons())
				m_totalBalance += amount;

			return;
		}
	}

	AddAccount(newPerson, amount);
}
void Bank::DeleteAccount(const Account& account) {
	bool y = false;
	int num = -1;
	for (int i = 0; i < m_numbeOfAccounts; i++)
	{
		if (m_account[i]->GetAccountNumber() == account.GetAccountNumber())
		{
			y = true;
			num = i;
		}
	}
	if (y = false)
		return;
	if (m_numbeOfAccounts = 1)
	{
		delete m_account[num];
		delete[] m_account;
		m_account = nullptr;
		m_totalBalance = m_totalBalance - account.GetBalance();
		m_numbeOfAccounts = 0;
	}
	else
	{
		m_totalBalance = m_totalBalance - account.GetBalance();
		Account** tempaco = new Account * [m_numbeOfAccounts - 1];
		for (int i = 0; i < m_numbeOfAccounts; i++)
		{
			if (i < num)
			{
				tempaco[i] = m_account[i];
			}
			if (i = num)
			{
				for (int t = num + 1; t < m_numbeOfAccounts; t++)
				{
					tempaco[num] = m_account[num + 1];
				}
				i = m_numbeOfAccounts;
			}
		}
		SetAccount(tempaco, m_numbeOfAccounts - 1);
	}
}
void Bank::DeletePerson(const Person& p)
{
	int i = 0;
	while (i < m_numbeOfAccounts)
	{
		m_account[i]->DeletePerson(p);
		if (0 == m_account[i]->GetTotalPersons())
			DeleteAccount(*m_account[i]);
		else
			++i;
	}
}