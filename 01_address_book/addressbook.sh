FILE="addressbook.txt"

# a) Create address book
createAddressBook() {
    if [ -e "$FILE" ]; then
        # -e returns true if the file exists. If not, it creates it using TOUCH
        echo "Address book already exist."
    else
        touch "$FILE"
        echo "Address book created."
    fi
}

# b) View address book
viewAddressBook() {
    if [ ! -s "$FILE" ]; then
        # -s: Tests if the file exists and is empty or not
        echo "Address book is empty or does not exist."
    else
        echo "---- Address Book ----"
        cat "$FILE"
        # cat prints the file contents to the screen.
    fi
}

# c) Insert a record
insertRecord() {
    echo "Enter record in format:LastName,FirstName,Email,Phone"
    read record
    echo "$record" >> "$FILE"
    echo "Record inserted."
}

# d) Delete a record
deleteRecord() {
    echo "Enter a search string (e.g name or email) to find the record to delete:"
    read search
    grep -n "$search" "$FILE"
    # grep -n: Searches the file and shows matching lines with line numbers (-n)

    echo "Enter line number to delete:"
    read line
    sed -i "${line}d" "$FILE"
    # sed -i "${line}d" deletes that line in-place.
    # sed -i specifies the address range either by line number.
    echo "Record deleted."
}

# e) Modify a record
modifyRecord() {
    echo "Enter a search string(e.g.name or email) to find the record to modify:"
    read search
    grep -n "$search" "$FILE"

    echo "Enter line number to modify:"
    read line

    echo "Enter new record(LastName,firstName,Email,Phone):"
    read newRecord
    sed -i "${line}s/.*/$newRecord/" "$FILE"
    echo "Record modified."
}

# f) Exit the program
exitProgram() {
    echo "Exiting...Goodbye!"
    exit 0
}

# menu loop
while true; do
    echo
    echo "====== Address Book Menu ======"
    echo "1. Create Address Book"
    echo "2. View Address Book"
    echo "3. Insert a Record"
    echo "4. Delete a Record"
    echo "5. Modify a Record"
    echo "6. Exit"
    echo "Enter your choice:"
    read choice

    case $choice in
        1) createAddressBook ;;
        2) viewAddressBook ;;
        3) insertRecord ;;
        4) deleteRecord ;;
        5) modifyRecord ;;
        6) exitProgram ;;
        *) echo "Invalid choice.Please select 1-6." ;;
    esac
done
