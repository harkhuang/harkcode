
#include <string>  
#include <vector>  
#include <iostream>  

using namespace std;  

class Menu    
{  
public:  
    virtual ~Menu();  

    virtual void Add(Menu*);  
    virtual void Remove(Menu*);  
    virtual Menu* GetChild(int);  
    virtual void Display() = 0;  
protected:  
    Menu();  
    Menu(std::string);  
    std::string m_strName;  
};  



Menu::Menu()  
{  

}  

Menu::Menu(std::string strName) : m_strName(strName)  
{  

}  

Menu::~Menu()  
{  

}  

void Menu::Add(Menu* pMenu)  
{}  

void Menu::Remove(Menu* pMenu)  
{}  

Menu* Menu::GetChild(int index)  
{  
    return NULL;  
}  

class SubMenu : public Menu    
{  
public:  
    SubMenu();  
    SubMenu(std::string);  
    virtual ~SubMenu();  

    void Display();  
};  


SubMenu::SubMenu()  
{  

}  

SubMenu::SubMenu(string strName) : Menu(strName)  
{  

}  

SubMenu::~SubMenu()  
{  

}  

void SubMenu::Display()  
{  
    cout << m_strName << endl;  
}  

//CompositMenu.h  


class CompositMenu : public Menu  
{  
public:  
    CompositMenu();  
    CompositMenu(std::string);  
    virtual ~CompositMenu();  

    void Add(Menu*);  
    void Remove(Menu*);  
    Menu* GetChild(int);  
    void Display();  
private:  
    std::vector<Menu*> m_vMenu;  
};  


CompositMenu::CompositMenu()  
{  

}  

CompositMenu::CompositMenu(string strName) : Menu(strName)  
{  

}  

CompositMenu::~CompositMenu()  
{  

}  

void CompositMenu::Add(Menu* pMenu)  
{  
    m_vMenu.push_back(pMenu);  
}  

void CompositMenu::Remove(Menu* pMenu)  
{  
    //m_vMenu.erase(&pMenu); 


    // 只找到一个
    //for (vector<Menu *>::iterator it = m_vMenu.begin();it !=  m_vMenu.end();it++ )
    //{
    //    if(pMenu == *it)
    //    {
    //        m_vMenu.erase( it );
    //        break;
    //    }
    //}



    // 这里找到了多个
    vector<Menu *>::iterator it_back;
    for (vector<Menu *>::iterator it = m_vMenu.begin();it !=  m_vMenu.end();it++ )
    {
        if(pMenu == *it)
        {
            it = m_vMenu.erase( it );
            it--;
           
        }
    }

}  

Menu* CompositMenu::GetChild(int index)  
{  
    return m_vMenu[index];  
}  

void CompositMenu::Display()  
{  
    cout << "+" << m_strName << endl;  
    vector<Menu*>::iterator it = m_vMenu.begin();  
    for (; it != m_vMenu.end(); ++it)  
    {  
        cout << "|-";  
        (*it)->Display();  
    }  
}  


int main(int argc, char* argv[])  
{  
    Menu* pMenu = new CompositMenu("国内新闻");  
    pMenu->Add(new SubMenu("时事新闻"));  
    pMenu->Add(new SubMenu("社会新闻"));  

    Menu* yuleNode = new SubMenu("娱乐新闻");
    pMenu->Add(yuleNode);  
    pMenu->Remove(yuleNode);
    pMenu->Display();
    pMenu = new CompositMenu("国际新闻");  
    pMenu->Add(new SubMenu("国际要闻"));  
    pMenu->Add(new SubMenu("环球视野"));  
    pMenu->Display();  

    return 0;  
}  