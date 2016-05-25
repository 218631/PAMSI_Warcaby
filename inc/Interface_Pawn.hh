#ifndef INTERFACE_PAWN_HH
#define INTERFACE_PAWN_HH

class Pawn{
public:
virtual void beat()=0;
virtual void combo_beat()=0;
virtual ~Pawn();
};

#endif
