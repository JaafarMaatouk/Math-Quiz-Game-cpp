# include<iostream>
using namespace std;

enum enQestionLevel { Easylevel = 1, Medlevel = 2, Hardlevel = 3, Mixlevel = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };

struct stQuestion
{

	short Number1 = 0;
	short Number2 = 0;
	enQestionLevel QestionLevel;
	enOperationType OperationType;
	short CorrectAnswar = 0;
	short PlayerAnswar = 0;
	bool AnswarResult = false;

};
struct stQuizz
{
	stQuestion QestionList[100];
	short QuestionNumber = 0;
	enQestionLevel QestionLevel;
	enOperationType OperationType;
	short NumberOfCorrectAnswars = 0;
	short NumberOfWrongAnswars = 0;
	bool IsPass = false;

};

enQestionLevel ReadQestionLevel() {

	short level;

	do {
		cout << "What is the Qesttions Level that do you want it? Easy[1], Mid[2], Hard[3], Mix[4]?\n";
		cin >> level;
	} while (level < 1 || level>4);

	return (enQestionLevel)level;
}

enOperationType ReadOperationType() {

	short Ope;
	do {
		cout << "What is the Operation that do you want it? Add[1], Sub[2], Mult[3], Div[4], Mix[5]?\n";
		cin >> Ope;
	} while (Ope < 1 || Ope>5);

	return (enOperationType)Ope;
}

short ReadNumberOfQestion() {

	short QestionNumber;
	do {

		cout << "How many Qustion to you want to Practice?\n";
		cin >> QestionNumber;
	} while (QestionNumber < 1 || QestionNumber>10);

	return QestionNumber;
}

short RandomNumber(short From, short To) {

	return rand() % (To - From + 1) + From;
}

int SimpleCalculate(int n1, int n2, enOperationType OperationType) {

	switch (OperationType)
	{
	case enOperationType::Add:
		return n1 + n2;

	case enOperationType::Sub:
		return n1 - n2;

	case enOperationType::Mul:
		return n1 * n2;

	case enOperationType::Div:
		return n1 / n2;

	}
}
stQuestion GenrateQestion(enQestionLevel QestionLevel, enOperationType OperationType) {

	stQuestion Qestion;
	if (QestionLevel == enQestionLevel::Mixlevel) {

		QestionLevel = (enQestionLevel)RandomNumber(1, 3);

	}

	if (OperationType == enOperationType::Mix) {

		OperationType = (enOperationType)RandomNumber(1, 4);
	}
	Qestion.OperationType = OperationType;

	switch (QestionLevel) {

	case enQestionLevel::Easylevel:
		Qestion.Number1 = RandomNumber(1, 10);
		Qestion.Number2 = RandomNumber(1, 10);
		Qestion.CorrectAnswar = SimpleCalculate(Qestion.Number1, Qestion.Number2, Qestion.OperationType);
		Qestion.QestionLevel = QestionLevel;

		return Qestion;

	case enQestionLevel::Medlevel:
		Qestion.Number1 = RandomNumber(10, 50);
		Qestion.Number2 = RandomNumber(10, 50);
		Qestion.CorrectAnswar = SimpleCalculate(Qestion.Number1, Qestion.Number2, Qestion.OperationType);
		Qestion.QestionLevel = QestionLevel;

		return Qestion;

	case enQestionLevel::Hardlevel:
		Qestion.Number1 = RandomNumber(50, 100);
		Qestion.Number2 = RandomNumber(50, 100);
		Qestion.CorrectAnswar = SimpleCalculate(Qestion.Number1, Qestion.Number2, Qestion.OperationType);
		Qestion.QestionLevel = QestionLevel;

		return Qestion;

	}
	return Qestion;

}

void GenerateQuizzQestions(stQuizz& Quizz) {

	for (short Qestion = 0; Qestion < Quizz.QuestionNumber; Qestion++) {

		Quizz.QestionList[Qestion] = GenrateQestion(Quizz.QestionLevel, Quizz.OperationType);
	}
}

char  PrintOPe(enOperationType Ope) {

	switch (Ope) {

	case enOperationType::Add:
		return '+';

	case enOperationType::Sub:
		return '-';

	case enOperationType::Mul:
		return '*';

	case enOperationType::Div:
		return '/';

	}
}
void PrintTheQuestion(stQuizz Quizz, short Num) {

	cout << "\n";
	cout << "Question[" << Num + 1 << "/" << Quizz.QuestionNumber << "]:\n\n";
	cout << Quizz.QestionList[Num].Number1 << endl;
	cout << Quizz.QestionList[Num].Number2 << " ";
	cout << PrintOPe(Quizz.QestionList[Num].OperationType) << endl;
	cout << "---------------\n";
}

int ReadPlayerAnsware() {

	int Number;
	cin >> Number;
	return Number;
}

void SetScreenColor(bool rigth) {

	if (rigth)
		system("color 2F");
	else
	{
		system("color 4F");
		cout << "\a";
	}
}
void CorrectTheQuestionAnsware(stQuizz& Quizz, short QuestionNumber) {

	if (Quizz.QestionList[QuestionNumber].PlayerAnswar != Quizz.QestionList[QuestionNumber].CorrectAnswar) {

		Quizz.QestionList[QuestionNumber].AnswarResult = false;
		Quizz.NumberOfWrongAnswars++;
		cout << "\nWrong Answare :(\n";
		cout << "The Rigth answare is :" << Quizz.QestionList[QuestionNumber].CorrectAnswar << "\n\n";
	}
	else {
		Quizz.QestionList[QuestionNumber].AnswarResult = true;
		Quizz.NumberOfCorrectAnswars++;
		cout << "Right Answare :)\n\n";
	}
	SetScreenColor(Quizz.QestionList[QuestionNumber].AnswarResult);
}
void AskAndCorrectQuizzQestion(stQuizz& Quizz) {
	for (short Question = 0; Question < Quizz.QuestionNumber; Question++) {

		PrintTheQuestion(Quizz, Question);

		Quizz.QestionList[Question].PlayerAnswar = ReadPlayerAnsware();

		CorrectTheQuestionAnsware(Quizz, Question);
	}

	Quizz.IsPass = (Quizz.NumberOfCorrectAnswars >= Quizz.NumberOfWrongAnswars);
}

string GetFinalResultTest(bool Pass) {
	if (Pass)
		return "Pass :)\n";
	else
		return "Fail :(\n";
}
string PrintLevel(enQestionLevel level) {

	switch (level) {

	case enQestionLevel::Easylevel:
		return "EasyLevel";

	case enQestionLevel::Medlevel:
		return "MedLevel";

	case enQestionLevel::Hardlevel:
		return "HardLevel";

	case enQestionLevel::Mixlevel:
		return "MexLevel";
	}
}
string PrintOpetext(enOperationType Ope) {

	switch (Ope) {

	case enOperationType::Add:
		return "Add";

	case enOperationType::Sub:
		return "Sub";

	case enOperationType::Mul:
		return "Mult";

	case enOperationType::Div:
		return "Div";

	case enOperationType::Mix:
		return "MixOpe";
	}
}
void PrintQuizzResult(stQuizz Quizz) {

	cout << "\n-------------------------------------\n\n";
	cout << "           Final Result is :" << GetFinalResultTest(Quizz.IsPass);
	SetScreenColor(Quizz.IsPass);
	cout << "\n-------------------------------------\n\n";

	cout << "Number of Qestion       :" << Quizz.QuestionNumber << endl;
	cout << "the level of question is:" << PrintLevel(Quizz.QestionLevel) << endl;
	cout << "the operation type        :" << PrintOpetext(Quizz.OperationType) << endl;

	cout << "Number of correct Answar:" << Quizz.NumberOfCorrectAnswars << endl;
	cout << "Number of wrong answare :" << Quizz.NumberOfWrongAnswars << endl;
	cout << "------------------------\n";


}

void PlayMathGame() {

	stQuizz Quizz;

	Quizz.QuestionNumber = ReadNumberOfQestion();
	Quizz.QestionLevel = ReadQestionLevel();
	Quizz.OperationType = ReadOperationType();

	GenerateQuizzQestions(Quizz);
	AskAndCorrectQuizzQestion(Quizz);
	PrintQuizzResult(Quizz);
}
void ResetScreen() {

	system("cls");
	system("color 0F");
}
void StartGame() {

	char PlayAgin = 'y';

	do {

		ResetScreen();
		PlayMathGame();

		cout << "Do you want to practice a new Quezze? y/n?";
		cin >> PlayAgin;

	} while (PlayAgin == 'y' || PlayAgin == 'Y');
}
int main() {

	srand((unsigned)time(NULL));

	StartGame();
}