#include <iostream> // کتابخانه‌ی استاندارد ورودی و خروجی C++ را به برنامه اضافه می‌کند
#include <string>   // کتابخانه‌ی مورد نیاز برای استفاده از رشته‌ها در C++ است
#include <cctype>   // کتابخانه‌ای برای بررسی ویژگی‌های کاراکترها مانند اعداد و حروف الفبا است

// تعریف توابع:

// تابع بررسی طول رمز عبور
bool hasMinimumLength(const std::string& password) {
    return password.length() >= 6; // اگر طول رمز عبور بیشتر مساوی ۶ باشد، true برمی‌گرداند
}

// تابع بررسی وجود عدد در رمز عبور
bool hasDigit(const std::string& password) {
    for (char c : password) { // برای هر کاراکتر در رمز عبور
        if (isdigit(c)) {     // اگر کاراکتر عددی باشد
            return true;      // true برمی‌گرداند
        }
    }
    return false;            // در غیر این صورت، false برمی‌گرداند
}

// تابع بررسی وجود حروف خاص در رمز عبور
bool hasSpecialCharacter(const std::string& password) {
    for (char c : password) {       // برای هر کاراکتر در رمز عبور
        if (!isalnum(c)) {          // اگر کاراکتر حروفی یا عددی نباشد
            return true;            // true برمی‌گرداند
        }
    }
    return false;                   // در غیر این صورت، false برمی‌گرداند
}

// تابع بررسی وجود حروف بزرگ در رمز عبور
bool hasUppercase(const std::string& password) {
    for (char c : password) {   // برای هر کاراکتر در رمز عبور
        if (isupper(c)) {       // اگر کاراکتر حرف بزرگ باشد
            return true;        // true برمی‌گرداند
        }
    }
    return false;               // در غیر این صورت، false برمی‌گرداند
}

// تابع بررسی وجود حروف کوچک در رمز عبور
bool hasLowercase(const std::string& password) {
    for (char c : password) {   // برای هر کاراکتر در رمز عبور
        if (islower(c)) {       // اگر کاراکتر حرف کوچک باشد
            return true;        // true برمی‌گرداند
        }
    }
    return false;               // در غیر این صورت، false برمی‌گرداند
}

// تابع بررسی میزان سختی رمز عبور با توجه به شرایط مشخص شده
int calculatePasswordStrength(const std::string& password) {
    int strength = 0; // امتیاز سختی رمز عبور

    if (hasMinimumLength(password)) {
        strength += 20; // اضافه کردن ۲۰ امتیاز به سختی رمز عبور
    }

    if (hasDigit(password)) {
        strength += 20; // اضافه کردن ۲۰ امتیاز به سختی رمز عبور
    }

    if (hasSpecialCharacter(password)) {
        strength += 20; // اضافه کردن ۲۰ امتیاز به سختی رمز عبور
    }

    if (hasUppercase(password)) {
        strength += 20; // اضافه کردن ۲۰ امتیاز به سختی رمز عبور
    }

    if (hasLowercase(password)) {
        strength += 20; // اضافه کردن ۲۰ امتیاز به سختی رمز عبور
    }

    return strength; // بازگشت امتیاز سختی رمز عبور
}

int main() {
    std::string password; // تعریف یک رشته برای ذخیره رمز عبور
    std::cout << "Enter your password: "; // نمایش پیام برای ورود رمز عبور
    std::cin >> password; // دریافت رمز عبور از کاربر

    int strength = calculatePasswordStrength(password); // محاسبه سختی رمز عبور

    std::cout << "Password strength: " << strength << "%" << std::endl; // نمایش سختی رمز عبور

    return 0; // بازگشت صفر به عنوان موفقیت آمیز اجرای برنامه
}
