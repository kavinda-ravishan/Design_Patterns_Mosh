#include <iostream>

class Tool
{
public:
    virtual void mouseDown() = 0;
    virtual void mouseUp() = 0;
};

class SelectionTool : public Tool
{
public:
    void mouseDown() override
    {
        std::cout << "Selection icon\n";
    }
    void mouseUp() override
    {
        std::cout << "Draw dashed rectangle\n";
    }
};

class BrushTool : public Tool
{
public:
    void mouseDown() override
    {
        std::cout << "Brush icon\n";
    }
    void mouseUp() override
    {
        std::cout << "Draw a line\n";
    }
};

class EraserTool : public Tool
{
public:
    void mouseDown() override
    {
        std::cout << "Eraser icon\n";
    }
    void mouseUp() override
    {
        std::cout << "Eraser object\n";
    }
};

class Canvas
{
private:
    Tool *currentTool;

public:
    void mouseDown()
    {
        currentTool->mouseDown();
    }
    void mouseUp()
    {
        currentTool->mouseUp();
    }
    Tool *getCurrentTool()
    {
        return currentTool;
    }
    void setCurrentTool(Tool *tool)
    {
        this->currentTool = tool;
    }
};

void state_test()
{
    Canvas canvas;

    SelectionTool selectionTool;
    BrushTool brushTool;
    EraserTool eraserTool;

    canvas.setCurrentTool(&selectionTool);
    canvas.mouseDown();
    canvas.mouseUp();

    canvas.setCurrentTool(&brushTool);
    canvas.mouseDown();
    canvas.mouseUp();

    canvas.setCurrentTool(&eraserTool);
    canvas.mouseDown();
    canvas.mouseUp();
}
