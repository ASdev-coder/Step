#include <iostream>
#include <windows.h>
#include <sstream>
#include <conio.h>

#pragma region Tools
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

// Set text and background color
void setColor(ConsoleColor textColor, ConsoleColor backgroundColor)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((backgroundColor << 4) | textColor));
}

// Reset console colors
void resetColor()
{
	setColor(ConsoleColor::White, ConsoleColor::Black);
}

// Set cursor position
void setCursorPosition(int x, int y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(hStdOut, coord);
}

struct Color
{
	short r;
	short g;
	short b;
};

// Draw line from a(x1;y1) to b(x2;y2)
void drawLine(int x1, int y1, int x2, int y2, int thick, Color color)
{
	POINT op;
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);
	HPEN Pen = CreatePen(PS_SOLID, thick, RGB(color.r, color.g, color.b));
	SelectObject(hDC, Pen);

	MoveToEx(hDC, x1, y1, &op);
	LineTo(hDC, x2, y2);
	ReleaseDC(hWnd, hDC);
	ReleaseDC(NULL, hDC);

}

// Draw a hollow circle with a black background
void drawCircle(int x, int y, int r, int thick, Color color)
{
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);

	SelectObject(hDC, CreatePen(PS_SOLID, thick, RGB(color.r, color.g, color.b)));
	SelectObject(hDC, CreateSolidBrush(RGB(0, 0, 0)));

	Ellipse(hDC, x - r, y - r, x + r, y + r);
	ReleaseDC(NULL, hDC);
}

// Draw a filled circle
void drawFilledCircle(int x, int y, int r, Color color)
{
	HWND hWnd = GetConsoleWindow();
	HDC hDC = GetDC(hWnd);

	SelectObject(hDC, CreateSolidBrush(RGB(color.r, color.g, color.b)));
	Ellipse(hDC, x - r, y - r, x + r, y + r);

	ReleaseDC(NULL, hDC);

}

#pragma endregion


struct MenuColors
{
public:
	ConsoleColor cursorColor{ ConsoleColor::Red };
	ConsoleColor bgColor{ ConsoleColor::Black };
	ConsoleColor textColor{ ConsoleColor::White };
};

class MenuItem
{
private:
	std::string title;
	const MenuColors* colors{ nullptr };

	std::string prepareText(int width)
	{
		int spacesCount = (width - this->getLength()) / 2;

		std::stringstream s;

		for (int i{}; i < spacesCount; ++i)
			s << ' ';

		s << this->title;

		for (int i{}; i < spacesCount; ++i)
			s << ' ';

		return s.str();
	}


public:
	MenuItem()
	{}
	MenuItem(const std::string& title, const MenuColors* colors):
		title{title},
		colors{colors}
	{}

	void setTitle(const std::string& title)
	{
		this->title = title;
	}

	void setColors(const MenuColors* colors)
	{
		this->colors = colors;
	}

	int getLength()
	{
		return this->title.length();
	}

	void render(int width, int x, int y, bool withCursor = false)
	{
		std::string text = this->prepareText(width);

		setCursorPosition(x, y);

		if (withCursor)
			setColor(this->colors->textColor, this->colors->cursorColor);
		else
			setColor(this->colors->textColor, this->colors->bgColor);

		std::cout << text;

		resetColor();
	}
};

enum MenuDirection
{
	Vertical,
	Horizontal,
};

enum Key
{
	Down = 115,
	Up = 119,
	Enter = 13
};

struct Point
{
	int x;
	int y;
};


class Menu
{
private:
	const int DEFAULT_GAP{ 3 };

	int count{ 0 };
	MenuItem* items{ nullptr };
	Point position{ 0, 0 };
	int gap{ Menu::DEFAULT_GAP };
	int selectedIndex{ 0 };
	MenuColors colors;

	int width{};

	int executeVertical()
	{
		while (true)
		{
			this->renderVertical();

			int input = this->getUserInput();

			this->items[this->selectedIndex].render(this->width, this->position.x, this->position.y + this->selectedIndex);

			switch (input)
			{
			case Key::Down:
				this->selectedIndex = this->selectedIndex == this->count - 1 ? 
					0 : 
					this->selectedIndex + 1;
				break;
			case Key::Up:
				this->selectedIndex = this->selectedIndex == 0 ?
					this->count - 1 :
					this->selectedIndex - 1;
				break;
			case Key::Enter:
				return this->selectedIndex;
				break;
			}

			this->items[this->selectedIndex].render(this->width, this->position.x, this->position.y + this->selectedIndex, true);

		}
		
	}

	void renderVertical()
	{
		for (int i{}; i < this->count; ++i)
		{
			bool withCorsor = this->selectedIndex == i;

			this->items[i].render(this->width, this->position.x, this->position.y + i, withCorsor);
		}
	}

	void calculateWidth()
	{
		int max{};

		for (int i{}; i < this->count; ++i)
			if (this->items[i].getLength() > max)
				max = this->items[i].getLength();

		this->width = max + this->gap * 2;
	}

	int getUserInput()
	{
		return _getch();
	}

public:
	Menu()
	{}
	Menu(int count, const std::string* items, const Point& position):
		count{count},
		items{ new MenuItem[count] {} },
		position{ position }
	{
		for (int i{}; i < this->count; ++i)
		{
			this->items[i].setTitle(items[i]);
			this->items[i].setColors(&(this->colors));
		}

		this->calculateWidth();	
	}

	int execute(MenuDirection direction = MenuDirection::Vertical)
	{
		switch (direction)
		{
		case MenuDirection::Vertical:
			return this->executeVertical();

		case MenuDirection::Horizontal:

			break;

		default:

			break;
		}
	}

	void setGap(int gap)
	{
		this->gap = gap;

		this->calculateWidth();
	}

	void setColors(ConsoleColor cursorColor, ConsoleColor bgColor, ConsoleColor textColor)
	{
		this->colors.cursorColor = cursorColor;
		this->colors.bgColor = bgColor;
		this->colors.textColor = textColor;
	}
};



int main()
{
	int count{ 5 };
	std::string* items = new std::string[count]
	{
		"item_0",
		"item_1",
		"item_2",
		"item_3",
		"item_4item_4",
	};

	Menu menu{ count, items, {10, 3} };
	menu.setColors(ConsoleColor::Green, ConsoleColor::LightGray, ConsoleColor::Black);

	switch (menu.execute())
	{
	case 0:
		std::cout << "item_0\n";
		break;
	case 1:
		std::cout << "item_1\n";
		break;
	case 2:
		std::cout << "item_2\n";
		break;
	case 3:
		std::cout << "item_3\n";
		break;
	case 4:
		std::cout << "item_4\n";
		break;
	}



}