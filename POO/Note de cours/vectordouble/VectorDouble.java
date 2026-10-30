package vectordouble;

public class VectorDouble {
    private double[] vector;
    private int capacity;
    private int size;

    public VectorDouble(){
        vector = new double[10];
        capacity = 10;
        size = 0;
    }

    private VectorDouble(int capacity){
        if(capacity <= 0){
            throw new IllegalArgumentException("Invalide size");
        }

        vector = new double[capacity];
        this.capacity = capacity;
        size = 0;
    }

    public int getSize(){
        return size;
    }

    public int getCapacity(){
        return capacity;
    }

    public boolean isEmpty(){
        return size == 0;
    }

    public double getAt(int idx){
        if(idx < 0 || idx >= size){
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return vector[idx];
    }

    public void setAt(int idx, double data){
        if(idx < 0 || idx >= size){
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        vector[idx] = data;
    }

    public void stretch(int newCapacity){
        if(newCapacity <= capacity){
            throw new IllegalArgumentException("Invalid capacity size");
        }
        VectorDouble newVector = new VectorDouble(newCapacity);

        for(int i = 0; i < size; ++i){
            newVector.vector[i] = this.vector[i];
        }
        newVector.size = this.size;

        this.vector = newVector.vector;
        this.capacity = newVector.capacity;
    }

    public void add(double data) {
        if(size == capacity){
            stretch(capacity * 2);
        }

        vector[size] = data;
        ++size;
    }

    public void removeLast(){
        if (isEmpty()){
            throw new IllegalStateException("Vector is already empty");
        }
        --size;
        vector[size] = 0.0;
    }

    public void insertAt(int idx, double value){
        //deplace les éléments

    }

    public void removeAt(int idx){
        //déplace les éléments
    }

    public void clear(){
        // vide le vector sans changer la capacité
    }
}

