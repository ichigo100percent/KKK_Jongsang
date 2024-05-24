#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Monster;
class Knight;

class Monster
{
public:
	Monster() { hp = 100; }

	int GetHP() { return hp; }
	void SetHP(int _hp) { hp = _hp; }

private:
	int hp;
};

class Knight
{
public:
	Knight() { hp = 100; damage = 5; }

	void SetTarget(shared_ptr<Monster> _monster)
	{
		target = _monster;
	}

	void Attack()
	{
		//if (target)
		//{
		//	target->SetHP(target->GetHP() - damage);
		//	cout << "몬스터 공격 성공! " << endl;
		//	return;
		//}
		//cout << "몬스터 공격 실패! " << endl;
		if (!target.expired())
		{
			if (auto t = target.lock())
			{
				t->SetHP(t->GetHP() - damage);
				cout << "몬스터 공격 성공! " << endl;
				return;
			}
		}
		cout << "몬스터 공격 실패! " << endl;
	}

	//void deleteTargrt()
	//{
	//	if (target)
	//	{
	//		target.reset();
	//		return;
	//	}
	//}

private:
	int hp;
	int damage;
	//shared_ptr<Monster> target;
	weak_ptr<Monster> target;
};



int main()
{
	auto knight = make_unique<Knight>();

	{
		auto monster = make_shared<Monster>();
		knight->SetTarget(monster);
		knight->Attack();
	}

	knight->Attack();

	return 0;
}