import mysql.connector

def get_connection():
    return mysql.connector.connect(
        host="localhost",
        user="root",
        password="root",
        database="taj"
    )

def fetch_records():
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute("SELECT `S. No.`, `Name Of The Guest`, `Room_No`, `Stay Duration`, `Price` FROM data")
        records = cursor.fetchall()
    return records

def add_record():
    name = input("Enter Name Of The Guest: ")
    room_no = int(input("Enter Room No.: "))
    duration = int(input("Enter Stay Duration (days)(2000 per day): "))
    price = 2000 * duration

    with get_connection() as conn:
        cursor = conn.cursor()
        query = "INSERT INTO data (`Name Of The Guest`, `Room_No`, `Stay Duration`, `Price`) VALUES (%s, %s, %s, %s)"
        cursor.execute(query, (name, room_no, duration, price))
        conn.commit()

    print(f"Record added successfully! The current bill is: ₹{price}")

def delete_record():
    s_no = int(input("Enter S. No. of the record to delete: "))
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute("DELETE FROM data WHERE `S. No.` = %s", (s_no,))
        conn.commit()
    print("Record deleted successfully!")

TAXI_PRICE_PER_HOUR = 1000

def call_taxi_service():
    display_records(fetch_records())
    room_no = int(input("Enter the Room No. of the guest: "))
    hours_needed = int(input("Enter the number of hours the taxi is needed (₹1000 per hour): "))
    total_price = hours_needed * TAXI_PRICE_PER_HOUR

    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute("INSERT INTO taxi_service (room_no, hours_needed, total_price) VALUES (%s, %s, %s)", 
                       (room_no, hours_needed, total_price))

        cursor.execute("SELECT price FROM data WHERE Room_No = %s", (room_no,))
        result = cursor.fetchone()

        if result:
            new_bill = result[0] + total_price
            cursor.execute("UPDATE data SET price = %s WHERE Room_No = %s", (new_bill, room_no))
            conn.commit()
            print(f"The taxi has been called for {hours_needed} hours. Total cost added to bill: ₹{total_price}")
        else:
            print("Guest not found!")

def display_food_menu():
    with get_connection() as conn:
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM food_menu")
        return cursor.fetchall()

def order_food():
    dishes = display_food_menu()
    print("\nFood Menu:")
    for dish in dishes:
        print(f"{dish[0]}. {dish[1]} - ₹{dish[2]}")

    room_no = int(input("Enter your Room No.: "))
    orders = []

    while True:
        dish_id = int(input("Enter the ID of the dish to order (0 to finish): "))
        if dish_id == 0:
            break
        quantity = int(input("Enter the quantity: "))

        if any(dish[0] == dish_id for dish in dishes):
            orders.append((room_no, dish_id, quantity))
        else:
            print("Invalid dish ID. Please select a valid dish.")

    if orders:
        total_price = sum(quantity * dish[2] for room_no, dish_id, quantity in orders if dish[0] == dish_id)
        
        with get_connection() as conn:
            cursor = conn.cursor()
            cursor.executemany("INSERT INTO guest_order (room_no, dish_id, quantity) VALUES (%s, %s, %s)", orders)
            cursor.execute("UPDATE data SET price = price + %s WHERE Room_No = %s", (total_price, room_no))
            conn.commit()
            
        print(f"Your food order has been placed! Total price for this order is ₹{total_price}.")
    else:
        print("No items were ordered.")

def display_guest_bill():
    room_no = int(input("Enter the Room No. of the guest: "))

    with get_connection() as conn:
        cursor = conn.cursor()

        cursor.execute("SELECT `Name Of The Guest`, `Stay Duration`, price FROM data WHERE `Room_No` = %s", (room_no,))
        guest_info = cursor.fetchone()

        if not guest_info:
            print("Guest not found!")
            return

        guest_name, stay_duration, total_price = guest_info

        cursor.execute("SELECT dish_name, quantity, price FROM food_orders JOIN food_menu ON food_orders.dish_id = food_menu.id WHERE room_no = %s", (room_no,))
        services = cursor.fetchall()

        cursor.execute("SELECT total_price FROM taxi_service WHERE room_no = %s", (room_no,))
        taxi_service_charge = cursor.fetchone()

        print("\nGuest Bill:")
        print(f"Guest Name: {guest_name}")
        print(f"Room No.: {room_no}")
        print(f"Stay Duration (days): {stay_duration}")
        print(f"Total Room Charges: ₹{total_price}")
        
        if taxi_service_charge:
            print(f"Taxi Service Charge: ₹{taxi_service_charge[0]}")

        if services:
            print("\nServices:")
            print("Service Name | Quantity | Price Per Unit | Total Price")
            for service in services:
                print(f"{service[0]} | {service[1]} | ₹{service[2]} | ₹{service[1] * service[2]}")

        final_bill = total_price + (taxi_service_charge[0] if taxi_service_charge else 0) + sum(service[1] * service[2] for service in services)
        print("\nFinal Bill: ₹{:.2f}".format(final_bill))

def display_records(records):
    print("\nRecords: \n|S.No.|Name|Room|Duration|Price|")
    for record in records:
        print(record)

def show_menu():
    print("\nChoose an option:")
    print("1. View Records")
    print("2. Add New Record")
    print("3. Delete Record")
    print("4. Call Taxi Service")
    print("5. Order Food")
    print("6. Show Final Bill")
    print("7. Quit")
    return input("Enter your choice: ")

def main():
    while True:
        choice = show_menu()
        if choice == "1":
            display_records(fetch_records())
        elif choice == "2":
            add_record()
        elif choice == "3":
            delete_record()
        elif choice == "4":
            call_taxi_service()
        elif choice == "5":
            order_food()
        elif choice == "6":
            display_guest_bill()
        elif choice == "7":
            print("Goodbye!")
            break
        else:
            print("Invalid choice! Please enter a valid option.")


main()