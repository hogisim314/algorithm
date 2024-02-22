select info.item_id as item_id, info.item_name as item_name, info.rarity as rarity
from 
(select tree.item_id as tree_item_id
     from item_info as info
     left outer join item_tree as tree
     on info.item_id = tree.parent_item_id
     where rarity = "RARE" and tree.item_id is not null) as k
     join item_info as info 
     on k.tree_item_id = info.item_id
order by item_id desc;