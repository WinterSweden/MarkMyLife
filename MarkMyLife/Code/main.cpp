#include <iostream>
#include <string>
#include <fstream>

int main() {
    int type, themeChoice;
    std::string name, email, summary, education, experience, skills;
    std::string dob, bloodType, allergies, medications, emergencyContact, medicalHistory;

    std::cout << "Welcome to MarkMyLife!\n\n";
    std::cout << "What would you like to prepare?\n";
    std::cout << "1. Curriculum Vitae\n";
    std::cout << "2. Resume\n";
    std::cout << "3. Medical Record\n";
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
    std::cout << "8. Festival 🎊\n";
    std::cout << "9. Professional Corporate\n";
    std::cout << "Enter theme number: ";
    std::cin >> themeChoice;
    std::cin.ignore();

    std::string docType;
    if (type == 1) docType = "Curriculum Vitae";
    else if (type == 2) docType = "Resume";
    else docType = "Medical Record";

    std::ofstream outFile("MML.md");

    // Header
    switch (themeChoice) {
        case 1: outFile << "# **" << docType << "**\n---\n\n"; break;
        case 2: outFile << "# 🎉 ~" << docType << "~ 🎉\n\n"; break;
        case 3: outFile << "# " << docType << "\n\n"; break;
        case 4: outFile << "# 🌸 " << docType << " 🌸\n\n"; break;
        case 5: outFile << "# ❄️ " << docType << " ❄️\n\n"; break;
        case 6: outFile << "# ☀️ " << docType << " ☀️\n\n"; break;
        case 7: outFile << "# 🌧️ " << docType << " 🌧️\n\n"; break;
        case 8: outFile << "# 🎊 " << docType << " 🎊\n\n"; break;
        case 9: outFile << "# **" << docType << "**\n\n"; break;
        default: std::cout << "Invalid theme choice!\n"; return 1;
    }

    std::cout << "\nEnter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your email: ";
    std::getline(std::cin, email);

    if (type == 3) {
        std::cout << "Enter your Date of Birth: ";
        std::getline(std::cin, dob);
        std::cout << "Enter your Blood Type: ";
        std::getline(std::cin, bloodType);
        std::cout << "Enter any Allergies: ";
        std::getline(std::cin, allergies);
        std::cout << "Enter Current Medications: ";
        std::getline(std::cin, medications);
        std::cout << "Emergency Contact (Name and Number): ";
        std::getline(std::cin, emergencyContact);
        std::cout << "Medical History Summary: ";
        std::getline(std::cin, medicalHistory);
    } else {
        std::cout << "Write a short summary about yourself: ";
        std::getline(std::cin, summary);
        if (type == 1) {
            std::cout << "Enter your education details: ";
            std::getline(std::cin, education);
        }
        std::cout << "Enter your experience details: ";
        std::getline(std::cin, experience);
        std::cout << "Enter your skills: ";
        std::getline(std::cin, skills);
    }

    // Output name and email
    if (themeChoice == 9) {
        outFile << "**Name:** *" << name << "*  \n";
        outFile << "**Email:** *" << email << "*\n\n";
    } else {
        outFile << "👤 **Name:** " << name << "\n\n✉️ **Email:** " << email << "\n\n";
    }

    // Output medical record or professional details
    if (type == 3) {
        outFile << "🩺 **Date of Birth:** " << dob << "\n";
        outFile << "🩸 **Blood Type:** " << bloodType << "\n";
        outFile << "🌿 **Allergies:** " << allergies << "\n";
        outFile << "💊 **Current Medications:** " << medications << "\n";
        outFile << "📞 **Emergency Contact:** " << emergencyContact << "\n";
        outFile << "📚 **Medical History:**\n" << medicalHistory << "\n";
    } else {
        if (themeChoice == 9)
            outFile << "**Summary:** *" << summary << "*\n\n";
        else if (themeChoice == 8)
            outFile << "🎇 **About Me:** " << summary << "\n\n";
        else
            outFile << "✨ **About Me:** " << summary << "\n\n";

        if (type == 1) {
            outFile << "🎓 **Education:**\n- " << education << "\n\n";
        }

        outFile << "💼 **Experience:**\n- " << experience << "\n\n";
        outFile << "🛠️ **Skills:**\n- " << skills << "\n";
    }

    outFile << "\n---\n";
    outFile << "*Crafted with care by **MarkMyLife***  \n";
    outFile << "*— Your story, beautifully told —*\n";
    outFile.close();

    std::cout << "\nYour themed document has been saved as MML.md\n";
    return 0;
}
