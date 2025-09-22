# spare_parts_inventory.py

def main():
    print("Hej. Welcome to the spare parts inventory!")
    inventory = {"hydraulic pump", "PLC module", "servo motor"}  # the parts you list in the chart

    def list_parts():
        parts_str = ", ".join(sorted(inventory, key=str.lower))
        print(f"We have {len(inventory)} part(s): {parts_str}")

    while True:
        user = input("Which part do you need? ").strip()

        # If the user asks what exists (per your flowchart example)
        if user.lower() in {
            "do you actually have any parts?",
            "do you actualy have any parts?",
            "what do you have?",
            "list",
            "inventory",
            "parts",
        }:
            list_parts()
            continue

        # Answer about availability of the requested item
        # (case-insensitive match against known parts)
        if any(user.lower() == p.lower() for p in inventory):
            print(f"I've got {user} here for you 😁")
        else:
            print(f"I am afraid we don't have any {user} in the inventory 😳")

        # The flowchart shows the dialog continuing after each answer,
        # so we loop forever. Press Ctrl+C to stop the program.

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("\nGoodbye!")
