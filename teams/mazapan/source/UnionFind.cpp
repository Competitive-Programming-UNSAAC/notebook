#define MAX 10005

int padre[ MAX ];
int rango[ MAX ];

void MakeSet( int n ){
    for( int i = 0 ; i < n ; ++i ){
        padre[ i ] = i;
        rango[ i ] = 0;
    }
}

int Find( int x ){
    if( x == padre[ x ] ) return x;
    else return Find( padre[ x ] );
    //else return padre[ x ] = Find( padre[ x ] );
}


void Union( int x , int y ){
    int xRoot = Find( x );
    int yRoot = Find( y );
    padre[ xRoot ] = yRoot;
}


void UnionbyRank( int x , int y ){
    int xRoot = Find( x );
    int yRoot = Find( y );
    if( rango[ xRoot ] > rango[ yRoot ] ){
        padre[ yRoot ] = xRoot;
    }
    else{              
        padre[ xRoot ] = yRoot;   
        if( rango[ xRoot ] == rango[ yRoot ] ){
            rango[ yRoot ]++;    
        }
    }
}

int root[ MAX ];
int numComponentes;

int getNumberConnectedComponents( int n ){
    numComponentes = 0;
    for( int i = 0 ; i < n ; ++i ){
        if( padre[ i ] == i ){
            root[ numComponentes++ ] = i;
        }
    }
    return numComponentes;
}

int numVertices[ MAX ];

void getNumberNodes( int n ){
    memset( numVertices , 0 , sizeof( numVertices ) );
    for( int i = 0 ; i < n ; ++i ){
        numVertices[ Find( i ) ]++;
    }
    for( int i = 0 ; i < numComponentes ; ++i ){
        printf("Componente %d: Raiz = %d , Nro nodos = %d.\n" , i + 1 , root[ i ] , numVertices[ root[ i ] ] );
    }
}

bool sameComponent( int x , int y ){
    if( Find( x ) == Find( y ) ) return true;
    return false;
}