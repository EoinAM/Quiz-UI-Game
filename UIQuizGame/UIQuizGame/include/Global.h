#ifndef GLOBAL_
#define GLOBAL_

struct ScreenSize
{
public:
	static const int s_width{ 1920 }, s_height{ 1080 };
};

class Settings
{
public:
	Settings(float t_animationScalar = 1.0f) : m_animationScalar(t_animationScalar) {}

	/// <summary>
	/// highest value this should be is 10, and the lowest it can be is 1
	/// </summary>
	float m_animationScalar;
};

enum CurrentScreen
{
	AUTHOR,
	LICENCE,
	SPLASH,
	STORY,
	MAINMENU,
	QuizSelect,
	PLAYING,
	OPTIONS_,
	Help,
	HIGHSCORE,
	CREDITS
};

enum class CurrentQuiz
{
	QUIZ1,
	QUIZ2,
	QUIZ3
};
#endif//!GLOBAL_