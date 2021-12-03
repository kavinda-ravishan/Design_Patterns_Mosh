#include <iostream>
#include <string>
#include <stack>

class EditorState
{
private:
    const std::string content;

public:
    EditorState(std::string content) : content(content) {}
    std::string getContent() { return content; }
};

class History
{
private:
    std::stack<EditorState> states;

public:
    void push(EditorState state)
    {
        states.push(state);
    }

    EditorState pop()
    {
        EditorState state = states.top();
        states.pop();
        return state;
    }
};

class Editor
{
private:
    std::string content;

public:
    std::string getContent() { return content; }

    void setContent(std::string content) { this->content = content; }

    EditorState createState()
    {
        EditorState state(content);
        return state;
    }

    void restore(EditorState state)
    {
        content = state.getContent();
    }
};

int main(int argc, char **argv)
{
    Editor editor;
    History history;

    editor.setContent("a");
    history.push(editor.createState());

    editor.setContent("b");
    history.push(editor.createState());

    editor.setContent("c");

    std::cout << editor.getContent() << std::endl;

    editor.restore(history.pop());
    std::cout << editor.getContent() << std::endl;

    editor.restore(history.pop());
    std::cout << editor.getContent() << std::endl;

    return 0;
}