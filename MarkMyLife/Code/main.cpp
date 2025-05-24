#include <iostream>
#include <string>
#include <fstream>

int main() {
    int type, themeChoice;
    std::string name, email, summary, education, experience, skills;

    std::cout << "Welcome to MarkMyLife!\n\n";
    std::cout << "What would you like to prepare?\n";
    std::cout << "1. Curriculum Vitae\n";
    std::cout << "2. Resume\n";
    std::cout << "Enter choice: ";
    std::cin >> type;
    std::cin.ignore();

    std::cout << "\nChoose a theme:\n";
    std::cout << "1. Elegant\n";
    std::cout << "2. Playful\n";
    std::cout << "3. Minimalist\n";
    std::cout << "Enter theme number: ";
    std::cin >> themeChoice;
    std::cin.ignore();

    std::cout << "\nEnter your full name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your email: ";
    std::getline(std::cin, email);

    std::cout << "Write a short summary about yourself: ";
    std::getline(std::cin, summary);

    std::ofstream outFile("output.md");

    // Write header based on theme and document type
    if (themeChoice == 1) { // Elegant
        outFile << "# **" << (type == 1 ? "Curriculum Vitae" : "Resume") << "**\n";
        outFile << "---\n\n";
    }
    else if (themeChoice == 2) { // Playful
        outFile << "# 🎉 ~" << (type == 1 ? "Curriculum Vitae" : "Resume") << "~ 🎉\n\n";
    }
    else if (themeChoice == 3) { // Minimalist
        outFile << "# " << (type == 1 ? "Curriculum Vitae" : "Resume") << "\n\n";
    }
    else {
        std::cout << "Invalid theme choice!\n";
        return 1;
    }

    // Name and Email formatting by theme
    if (themeChoice == 1) { // Elegant
        outFile << "_Name:_ **" << name << "**  \n";
        outFile << "_Email:_ **" << email << "**\n\n";
        outFile << "---\n\n";
    }
    else if (themeChoice == 2) { // Playful
        outFile << "👤 **Name:** " << name << "\n\n";
        outFile << "✉️ **Email:** " << email << "\n\n";
    }
    else if (themeChoice == 3) { // Minimalist
        outFile << "Name: " << name << "\n\n";
        outFile << "Email: " << email << "\n\n";
    }

    // Summary section
    if (themeChoice == 1) outFile << "### _Summary_\n" << summary << "\n\n";
    else if (themeChoice == 2) outFile << "✨ **About Me:** " << summary << "\n\n";
    else outFile << "Summary:\n" << summary << "\n\n";

    // Collect and output sections based on type
    if (type == 1) { // CV
        std::cout << "Enter your education details: ";
        std::getline(std::cin, education);
        std::cout << "Enter your experience details: ";
        std::getline(std::cin, experience);
        std::cout << "Enter your skills: ";
        std::getline(std::cin, skills);

        if (themeChoice == 1) { // Elegant
            outFile << "### _Education_\n" << education << "\n\n";
            outFile << "### _Experience_\n" << experience << "\n\n";
            outFile << "### _Skills_\n" << skills << "\n";
        }
        else if (themeChoice == 2) { // Playful
            outFile << "🎓 **Education:**\n- " << education << "\n\n";
            outFile << "💼 **Experience:**\n- " << experience << "\n\n";
            outFile << "🛠 **Skills:**\n- " << skills << "\n";
        }
        else { // Minimalist
            outFile << "Education:\n" << education << "\n\n";
            outFile << "Experience:\n" << experience << "\n\n";
            outFile << "Skills:\n" << skills << "\n";
        }

    } else if (type == 2) { // Resume
        std::cout << "Enter your experience summary: ";
        std::getline(std::cin, experience);
        std::cout << "Enter your key skills (comma separated): ";
        std::getline(std::cin, skills);

        if (themeChoice == 1) { // Elegant
            outFile << "### _Experience_\n" << experience << "\n\n";
            outFile << "### _Skills_\n" << skills << "\n";
        }
        else if (themeChoice == 2) { // Playful
            outFile << "💼 **Experience:**\n- " << experience << "\n\n";
            outFile << "🛠 **Skills:**\n- " << skills << "\n";
        }
        else { // Minimalist
            outFile << "Experience:\n" << experience << "\n\n";
            outFile << "Skills:\n" << skills << "\n";
        }
    }

    // Elegant watermark/footer at the end
    outFile << "\n---\n";
    outFile << "*Crafted with care by **MarkMyLife***  \n";
    outFile << "*— Your story, beautifully told —*\n";

    outFile.close();
    std::cout << "\nYour themed document has been saved as output.md\n";

    return 0;
}
