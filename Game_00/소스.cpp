#define USED_MAP
#undef  USED_MAP

#include "std.h"
#include "NonPersonCharacter.h"
#include "PersonCharacter.h"

std::wstring g_FindName;
bool CheckName(Character* p)
{
	if (p->m_csName == g_FindName)
	{
		return true;
	}
	return false;
}

class Enemy
{
public:
	Enemy() {}
};

int main()
{
#ifdef USED_MAP
	std::map<std::wstring, Character*> g_CharacterList;
#else
	std::vector<Character*> g_CharacterList;
#endif 
	Character* findObjAdd = nullptr;
	for (int i = 0; i < 10; i++)
	{
		Character* list0 = new NonPersonCharacter;
		if (i == 0)
		{
			findObjAdd = list0;
		}
		Point p = { 30 * i, 30 * i };
		list0->SetPos(p);
		list0->m_csName = L"000" + std::to_wstring(i);
#ifndef USED_MAP
		g_CharacterList.push_back(list0);
#else
		g_CharacterList.insert(std::make_pair(list0->m_csName, list0));
#endif // !USED_MAP
	}

#ifdef USED_MAP
	auto bFindObj = g_CharacterList.find(L"0002");
	if (bFindObj != g_CharacterList.end())
	{
		std::cout << " find=" << bFindObj->second;
	}
#else
	g_FindName = L"0002";
	auto bFindObj = std::find_if(g_CharacterList.begin(),
								 g_CharacterList.end(), CheckName);
	if (bFindObj != g_CharacterList.end())
	{
		std::cout << " find=" << *bFindObj;
	}
#endif // USED_MAP

#ifdef USED_MAP
	for (std::pair<const std::wstring, TCharacter*>& data : g_CharacterList)
#else
	for (auto pNode : g_CharacterList)
#endif // USED_MAP
	{
#ifdef USED_MAP
		TCharacter* pNode = data.second;
		pNode->SetHealth(50);
#else
		pNode->SetHealth(50);
#endif // USED_MAP
		NonPersonCharacter* pc1 = dynamic_cast<NonPersonCharacter*>(pNode);
		PersonCharacter* pc2 = dynamic_cast<PersonCharacter*>(pNode);

		NonPersonCharacter* pc3 = static_cast<NonPersonCharacter*>(pNode);
		PersonCharacter* pc4 = static_cast<PersonCharacter*>(pNode);

		if (pc2 != nullptr)
		{
			pc2->SetExperience(5);
		}
	}
#ifdef USED_MAP
	for (auto& pNode : g_CharacterList)
	{
		std::cout << pNode.second << std::endl;
	}
	for (auto& pNode : g_CharacterList)
	{
		delete pNode.second;
	}
#else
	for (auto pNode : g_CharacterList)
	{
		std::cout << pNode << std::endl;
	}
	for (auto pNode : g_CharacterList)
	{
		delete pNode;
	}
#endif   

	std::cout << "Hello World!\n";
}