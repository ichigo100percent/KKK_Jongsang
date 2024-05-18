#include <stdio.h>
#include <functional>
#include <iostream>

#define BIND_MEMBER_FUNC(func, obj) std::bind(&func, std::ref(obj))


using DialogueFunc = std::function<int(void)>;

class DialogueCallback
{
public:
	DialogueCallback()
	{
		m_dialogueFunc = nullptr;
	}

	explicit DialogueCallback(DialogueFunc _dialogueFunc)
	{
		m_dialogueFunc = _dialogueFunc;
	}

	int CallDialogue()
	{
		return m_dialogueFunc();
	}

	void setDialogueFunc(DialogueFunc _dialogueFunc)
	{
		m_dialogueFunc = _dialogueFunc;
	}

private:
	DialogueFunc m_dialogueFunc;
};


class BlackSmith
{
public:
	BlackSmith()
	{
		m_bReinforcementResult = true;
		m_reinforcementProbability = 100;
	}

	int sayHello()
	{
		printf("����~ ����ðԳ�!\n");
		return 0;
	}

	int InformReinforcementResult()
	{
		if (m_bReinforcementResult)
		{
			m_reinforcementProbability -= 70;
			printf("��~ ��ȭ �����̱���!\n");
		}
		else
		{
			m_reinforcementProbability += 5;
			printf("������ ���� �̲�������~\n");
		}
		return 0;
	}

	void setReinforcementResult(bool _bReinforcementResult)
	{
		m_bReinforcementResult = _bReinforcementResult;
	}

private:
	bool m_bReinforcementResult;
	int m_reinforcementProbability;

};

class Merchant
{
public:
	Merchant()
	{
		m_bSaleResult = true;
	}

	int InformSellResult()
	{
		if (m_bSaleResult)
		{
			printf("����~ �� ������ ���� ��鿴��.\n");
		}
		else
		{
			printf("��... ������ �ٲ��������.\n");
		}
		return 0;
	}

	void setSaleResult(bool _bSaleResult)
	{
		m_bSaleResult = _bSaleResult;
	}
private:
	bool m_bSaleResult;
};


int main()
{
	printf("<<ù ��°�� ���尣 ��ȭ�Դϴ�.>>\n");
	BlackSmith blacksmith;
	DialogueCallback blacksmithDialogue(BIND_MEMBER_FUNC(BlackSmith::sayHello, blacksmith));
	blacksmithDialogue.CallDialogue();

	blacksmithDialogue.setDialogueFunc(BIND_MEMBER_FUNC(BlackSmith::InformReinforcementResult, blacksmith));
	blacksmithDialogue.CallDialogue();

	blacksmith.setReinforcementResult(false);
	blacksmithDialogue.CallDialogue();
	printf("\n");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("<<�� ��°�� ���� ��ȭ �Դϴ�.>>\n");
	Merchant merchant;
	DialogueCallback merchantDialogue(BIND_MEMBER_FUNC(Merchant::InformSellResult, merchant));
	merchantDialogue.CallDialogue();

	merchant.setSaleResult(false);
	merchantDialogue.CallDialogue();

	return 0;
}