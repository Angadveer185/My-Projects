import math

def calculator():
    print("Welcome to the calculator!")
    print("Please choose an operation:")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Exponentiation")
    print("6. Square Root")
    print("7. Logarithm")
    print("8. Trigonometric Functions")
    
    choice = int(input("Enter your choice (1-8): "))
    
    if choice == 1:
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        print("The result is", num1 + num2)
        
    elif choice == 2:
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        print("The result is", num1 - num2)
        
    elif choice == 3:
        num1 = float(input("Enter the first number: "))
        num2 = float(input("Enter the second number: "))
        print("The result is", num1 * num2)
        
    elif choice == 4:
        try:
            num1 = float(input("Enter the first number: "))
            num2 = float(input("Enter the second number: "))
            print("The result is", num1 / num2)
        except ZeroDivisionError:
                print("Number Cannot Be Divided By Zero")
        
    elif choice == 5:
        num1 = float(input("Enter the base: "))
        num2 = float(input("Enter the exponent: "))
        print("The result is", num1 ** num2)
        
    elif choice == 6:
        num = float(input("Enter a number: "))
        print("The square root of", num, "is", math.sqrt(num))
        
    elif choice == 7:
        num = float(input("Enter a number: "))
        base = float(input("Enter the base of the logarithm (default is e): ") or "e")
        print("The logarithm of", num, "with base", base, "is", math.log(num, base))
        
    elif choice == 8:
        angle = float(input("Enter an angle in degrees: "))
        print("The sine of", angle, "is", math.sin(math.radians(angle)))
        print("The cosine of", angle, "is", math.cos(math.radians(angle)))
        print("The tangent of", angle, "is", math.tan(math.radians(angle)))
        
    else:
        print("Invalid choice. Please try again.")
        calculator()

calculator()
