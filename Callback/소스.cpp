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
		printf("여어~ 어서오시게나!\n");
		return 0;
	}

	int InformReinforcementResult()
	{
		if (m_bReinforcementResult)
		{
			m_reinforcementProbability -= 70;
			printf("자~ 강화 성공이구나!\n");
		}
		else
		{
			m_reinforcementProbability += 5;
			printf("어이쿠 손이 미끄러졌네~\n");
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
			printf("좋아~ 그 물건은 내가 사들였네.\n");
		}
		else
		{
			printf("흠... 마음이 바뀌었나보군.\n");
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
	printf("<<첫 번째는 대장간 대화입니다.>>\n");
	BlackSmith blacksmith;
	DialogueCallback blacksmithDialogue(BIND_MEMBER_FUNC(BlackSmith::sayHello, blacksmith));
	blacksmithDialogue.CallDialogue();

	blacksmithDialogue.setDialogueFunc(BIND_MEMBER_FUNC(BlackSmith::InformReinforcementResult, blacksmith));
	blacksmithDialogue.CallDialogue();

	blacksmith.setReinforcementResult(false);
	blacksmithDialogue.CallDialogue();
	printf("\n");

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("<<두 번째는 상점 대화 입니다.>>\n");
	Merchant merchant;
	DialogueCallback merchantDialogue(BIND_MEMBER_FUNC(Merchant::InformSellResult, merchant));
	merchantDialogue.CallDialogue();

	merchant.setSaleResult(false);
	merchantDialogue.CallDialogue();

	return 0;
}