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
    std::cout << "4. Floral 🌸\n";
    std::cout << "5. Winter ❄️\n";
    std::cout << "6. Summer ☀️\n";
    std::cout << "7. Rainy 🌧️\n";
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

    // Header
    switch (themeChoice) {
        case 1: outFile << "# **" << (type == 1 ? "Curriculum Vitae" : "Resume") << "**\n---\n\n"; break;
        case 2: outFile << "# 🎉 ~" << (type == 1 ? "Curriculum Vitae" : "Resume") << "~ 🎉\n\n"; break;
        case 3: outFile << "# " << (type == 1 ? "Curriculum Vitae" : "Resume") << "\n\n"; break;
        case 4: outFile << "# 🌸 " << (type == 1 ? "Curriculum Vitae" : "Resume") << " 🌸\n\n"; break;
        case 5: outFile << "# ❄️ " << (type == 1 ? "Curriculum Vitae" : "Resume") << " ❄️\n\n"; break;
        case 6: outFile << "# ☀️ " << (type == 1 ? "Curriculum Vitae" : "Resume") << " ☀️\n\n"; break;
        case 7: outFile << "# 🌧️ " << (type == 1 ? "Curriculum Vitae" : "Resume") << " 🌧️\n\n"; break;
        default:
            std::cout << "Invalid theme choice!\n";
            return 1;
    }

    // Personal Info
    if (themeChoice == 1 || themeChoice == 5) {
        outFile << "_Name:_ **" << name << "**  \n_Email:_ **" << email << "**\n\n---\n\n";
    } else if (themeChoice == 2 || themeChoice == 6) {
        outFile << "👤 **Name:** " << name << "\n\n✉️ **Email:** " << email << "\n\n";
    } else if (themeChoice == 3) {
        outFile << "Name: " << name << "\n\nEmail: " << email << "\n\n";
    } else if (themeChoice == 4 || themeChoice == 7) {
        outFile << "**👩‍🎓 Name:** _" << name << "_  \n**📬 Email:** _" << email << "_\n\n";
    }

    // Summary
    if (themeChoice == 1 || themeChoice == 5) outFile << "### _Summary_\n" << summary << "\n\n";
    else if (themeChoice == 2 || themeChoice == 6) outFile << "✨ **About Me:** " << summary << "\n\n";
    else if (themeChoice == 3) outFile << "Summary:\n" << summary << "\n\n";
    else outFile << "**📝 Summary:**\n" << summary << "\n\n";

    // Content
    if (type == 1) {
        std::cout << "Enter your education details: ";
        std::getline(std::cin, education);
        std::cout << "Enter your experience details: ";
        std::getline(std::cin, experience);
        std::cout << "Enter your skills: ";
        std::getline(std::cin, skills);

        if (themeChoice == 1 || themeChoice == 5) {
            outFile << "### _Education_\n" << education << "\n\n";
            outFile << "### _Experience_\n" << experience << "\n\n";
            outFile << "### _Skills_\n" << skills << "\n";
        } else if (themeChoice == 2 || themeChoice == 6) {
            outFile << "🎓 **Education:**\n- " << education << "\n\n";
            outFile << "💼 **Experience:**\n- " << experience << "\n\n";
            outFile << "🛠 **Skills:**\n- " << skills << "\n";
        } else if (themeChoice == 3) {
            outFile << "Education:\n" << education << "\n\n";
            outFile << "Experience:\n" << experience << "\n\n";
            outFile << "Skills:\n" << skills << "\n";
        } else {
            outFile << "🌼 **Education:**\n" << education << "\n\n";
            outFile << "🌱 **Experience:**\n" << experience << "\n\n";
            outFile << "🍀 **Skills:**\n" << skills << "\n";
        }

    } else {
        std::cout << "Enter your experience summary: ";
        std::getline(std::cin, experience);
        std::cout << "Enter your key skills (comma separated): ";
        std::getline(std::cin, skills);

        if (themeChoice == 1 || themeChoice == 5) {
            outFile << "### _Experience_\n" << experience << "\n\n";
            outFile << "### _Skills_\n" << skills << "\n";
        } else if (themeChoice == 2 || themeChoice == 6) {
            outFile << "💼 **Experience:**\n- " << experience << "\n\n";
            outFile << "🛠 **Skills:**\n- " << skills << "\n";
        } else if (themeChoice == 3) {
            outFile << "Experience:\n" << experience << "\n\n";
            outFile << "Skills:\n" << skills << "\n";
        } else {
            outFile << "🌦️ **Experience:**\n" << experience << "\n\n";
            outFile << "🌈 **Skills:**\n" << skills << "\n";
        }
    }

    // Watermark
    outFile << "\n---\n";
    outFile << "*Crafted with care by **MarkMyLife***  \n";
    outFile << "*— Your story, beautifully told —*\n";

    outFile.close();
    std::cout << "\nYour themed document has been saved as `output.md`\n";
    std::cout << "\nUse www.markdowntopdf.com to convert output.md to a REAL resume!\n";

    return 0;
}
