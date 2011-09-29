UPDATE creature_proto SET modImmunities=503 WHERE entry IN ( SELECT entry FROM creature_names WHERE rank=4 );

