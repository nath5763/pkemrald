import re

def fix_trainer_parties():
    file_path = "src/data/trainer_parties.h"
    
    with open(file_path, "r") as f:
        content = f.read()

    # 1. Clean up duplicated fields globally to revert the file to its original state.
    # This matches the pattern where a new level/species was appended without removing the old one.
    pattern_corrupted = r'(\.lvl\s*=\s*\d+,\s*\.species\s*=\s*SPECIES_[A-Z_]+,)\s*\.lvl\s*=\s*\d+,\s*\.species\s*=\s*SPECIES_[A-Z_]+,'
    content = re.sub(pattern_corrupted, r'\1', content)

    # 2. Target ONLY the specific trainers physically located on Routes 124 through 131.
    target_trainers = {
        "Declan", "Spencer", "Roland", "Chad", "Grace", 
        "Jenny1", "Jenny2", "Jenny3", "Jenny4", "Jenny5", 
        "Isabella", "Katelyn1", "Katelyn2", "Katelyn3", "Katelyn4", "Katelyn5", 
        "Talia", "Kai", "LilaAndRoy1", "LilaAndRoy2", "LilaAndRoy3", "LilaAndRoy4", "LilaAndRoy5", 
        "Stan", "Tanya", "Sharon", "Nolen", "Duncan", "LisaAndRay", "Auron", "Macey", 
        "Barry", "Dean", "Jack", "Nikki", "Brenda", 
        "Pablo1", "Pablo2", "Pablo3", "Pablo4", "Pablo5", 
        "Camden", "Isobel", "Donny", "Koji1", "Koji2", "Koji3", "Koji4", "Koji5", 
        "Conor", "Hudson", "Franklin", 
        "Harrison", "Carlee", "Isaiah1", "Isaiah2", "Isaiah3", "Isaiah4", "Isaiah5", "Katie", 
        "Reed", "Chase", "Allison", "Tisha", 
        "Rodney", "Santiago", "Kevin", 
        "Richard", "Herman", "Susie", "Kara", "Dana", "Sienna", "Linda", "Laurel", "ReliAndIan"
    }

    def process_trainer_block(match):
        header = match.group(1)
        trainer_name = match.group(2)
        body = match.group(3)
        
        # Skip trainers not explicitly on Routes 124-131
        if trainer_name not in target_trainers:
            return match.group(0)
            
        def update_mon(m):
            lvl = int(m.group(1))
            species = m.group(2)
            
            # Scale the level for all Pokemon in these parties
            if lvl < 41:
                new_lvl = min(max(lvl + 12, 41), 46)
            else:
                new_lvl = min(lvl, 46)
                
            return f".lvl = {new_lvl},\n    .species = {species},"
            
        new_body = re.sub(r'\.lvl\s*=\s*(\d+),\s*\.species\s*=\s*(SPECIES_[A-Z_]+),', update_mon, body)
        return f"{header} sParty_{trainer_name}[] = {{{new_body}\n}};"

    # Find and process the C structs for trainer parties
    pattern_trainer = r'(static const struct [A-Za-z0-9_]+) sParty_([A-Za-z0-9_]+)\[\] = \{([\s\S]*?)\n\};'
    content = re.sub(pattern_trainer, process_trainer_block, content)

    # Write the fixed content back to the file
    with open(file_path, "w") as f:
        f.write(content)

    print("Successfully updated all Route 124-131 trainers' Pokémon levels.")

if __name__ == "__main__":
    fix_trainer_parties()
