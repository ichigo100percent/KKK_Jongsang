#include "BuddyList.h"

using namespace std;

void BuddyList::addBuddy(const std::string& name, const std::string& buddy)
{
	//���⼭ ������ buddy�� �̹� ��� ���� �ʴ��� Ȯ���Ѵ�.
	if (!isBuddy(name, buddy))
	{
		mBuddies.emplace(name, buddy);
	}
}

void BuddyList::removeBuddy(const std::string& name, const std::string& buddy)
{
	//'name' Ű�� ���� ������ ����(���۰� ��)�� ���Ѵ�.
	//���⼭�� lower_bound()�� upper_bound()�� ����ϴ� ������� �����Ѵ�.
	//���������� equal_range()�� �����ϴ� ���� �� ȿ�����̴�.
	auto begin = mBuddies.lower_bound(name);	//������ ����
	auto end = mBuddies.upper_bound(name);		//������ ��

	//Ű�� 'name'�� ���ҿ� ���� �ݺ��ϸ鼭 'buddy'�� ���Ҹ� ã�´�.
	//Ű�� 'name'�� ���Ұ� ���ٸ� begin�� end�� �����Ƿ� ������ ������� �ʴ´�.
	for (auto iter = begin; iter != end; ++iter)
	{
		if (iter->second == buddy)
		{
			//��ġ�ϴ� ���Ҹ� ã�Ҵٸ� �ʿ��� �����Ѵ�.
			mBuddies.erase(iter);
			break;
		}
	}
}

bool BuddyList::isBuddy(const std::string& name, const std::string& buddy) const
{
	//equal_range()�� 'name' Ű�� ���� ���� ������ ���۰� ���� ���Ѵ�.
	//���⼭ C++17 ������ ���ε��� ����Ѵ�.
	auto [begin, end] = mBuddies.equal_range(name);

	//���� ����ϴ� �����Ϸ��� C++17 ������ ���ε��� �������� �ʴ´ٸ� ������ ���� �ۼ��Ѵ�.
	//auto range = mBuddies.equal_range(name);
	//auto begin = range.first;
	//auto end = range.second;

	//'name' Ű�� ���� ���ҿ� ���� �ݺ��ϸ鼭 ���� 'buddy'�� ���Ҹ� ã�´�.
	for (auto iter = begin; iter != end; ++iter)
	{
		if (iter->second == buddy)
		{
			//���Ҹ� ã�� ���
			return true;
		}
	}

	//���Ҹ� ã�� ���� ���
	return false;
}

std::vector<std::string> BuddyList::getBuddies(const std::string name) const
{
	//equal_range()�� 'name'Ű�� ���� ���� ������ ���۰� ���� ���Ѵ�.
	//���⼭ C++17 ������ ���ε��� ����Ѵ�.
	auto [begin, end] = mBuddies.equal_range(name);

	//�տ��� ���� ������ ���� �̸��� ��� vector�� ��´�.
	vector<string> buddies;
	for (auto iter = begin; iter != end; ++iter)
	{
		buddies.push_back(iter->second);
	}

	return buddies;
}


