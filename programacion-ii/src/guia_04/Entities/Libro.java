package guia_04.Entities;

public class Libro {
    private static int contadorId = 0;
    private int id;
    private String titulo;
    private String autor;
    private double precio;
    private int cantidadDeCopiasDisponibles;

    public Libro(String titulo, String autor, double precio, int cantidadDeCopiasDisponibles) {
        this.id = ++contadorId;
        this.titulo = titulo;
        this.autor = autor;
        this.precio = precio;
        this.cantidadDeCopiasDisponibles = cantidadDeCopiasDisponibles;
    }

    public int getCantidadDeCopiasDisponibles() { return cantidadDeCopiasDisponibles; }
    public void setCantidadDeCopiasDisponibles(int cantidad) { this.cantidadDeCopiasDisponibles = cantidad; }

    public int getId() { return id; }
    public double getPrecio() { return precio; }
    public void setPrecio(double precio) { this.precio = precio; }

    public String getAutor() { return autor; }
    public void setAutor(String autor) { this.autor = autor; }

    public String getTitulo() { return titulo; }
    public void setTitulo(String titulo) { this.titulo = titulo; }

    // Lógica de negocio
    public boolean venderLibros(int cantidad) {
        if (cantidad <= 0 || cantidad > cantidadDeCopiasDisponibles) {
            return false;
        }
        cantidadDeCopiasDisponibles -= cantidad;
        return true;
    }

    public boolean incrementarStock(int cantidad) {
        if (cantidad <= 0) return false;
        cantidadDeCopiasDisponibles += cantidad;
        return true;
    }

    @Override
    public String toString() {
        return String.format("Libro{id=%d, titulo='%s', autor='%s', precio=%.2f, stock=%d}",
                id, titulo, autor, precio, cantidadDeCopiasDisponibles);
    }
}
