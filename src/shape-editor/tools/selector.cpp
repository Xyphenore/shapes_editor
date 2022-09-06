#include "../../../include/shape-editor/tools/selector.hpp"

Selector::Selector()
        : selectedArray() {

}

Selector::Selector( const Selector& src )
        : selectedArray() {
    for ( size_t i = 0; i < src.selectedArray.size(); i++ ) {
        selectedArray[i] = src.selectedArray[i];
    }
}

Selector::~Selector() {

}

void Selector::add( Shape* newp ) {
    bool canAdd = true;
    for ( unsigned i = 0; i < selectedArray.size(); i++ ) {
        if ( selectedArray.at( i ) == newp ) {
            canAdd = false;
            Shape* tmp = selectedArray.at( 0 );
            selectedArray[0] = selectedArray[i];
            selectedArray.at( i ) = tmp;
            newp->setSelected( true );
        }
    }

    if ( canAdd ) {
        this->selectedArray.push_back( newp );
        //newp->setSelected(true);
    }
}

void Selector::clear() {
    for ( size_t i = 0; i < selectedArray.size(); i++ ) {
        selectedArray.at( i )->setSelected( false );
        //selectedArray.at(i)->setActived(false);
    }

    selectedArray.clear();

}

bool Selector::isSelected( const Shape* p ) const {
    if ( p != nullptr ) {
        for ( auto& i: selectedArray ) {
            if ( i == p ) {
                return true;
            }
        }
    }
    return false;
}

void Selector::clearExpecptfirst() {
    if ( !selectedArray.empty() ) {
        Shape* tmp = selectedArray.at( 0 );
        selectedArray.clear();
        add( tmp );
    }
}

void Selector::paintSelected( EZWindow Win ) {
    Win.setColor( ez_red );
    for ( unsigned i = 0; i < selectedArray.size(); i++ ) {
        selectedArray.at( i )->draw( Win );
    }
    Win.setColor( ez_black );
}

void Selector::setFirstPlace( Shape* p1 ) {
    if ( isSelected( p1 ) ) {
        Shape* tmp_S;
        for ( size_t i = 0; i < selectedArray.size(); i++ ) {
            if ( selectedArray.at( i ) == p1 ) {
                tmp_S = selectedArray.at( 0 );
                selectedArray.at( 0 ) = p1;
                selectedArray.at( i ) = tmp_S;
            }
        }
    }
}
