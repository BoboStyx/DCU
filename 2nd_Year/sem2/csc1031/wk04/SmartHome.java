public class SmartHome {

    static class Appliance {
        private String brand;
        private double powerConsumption;

        public Appliance(String brand, double powerConsumption) {
            this.brand = brand;
            this.powerConsumption = powerConsumption;
        }

        public void turnOn() {
            System.out.println("Turning on " + brand + " appliance");
        }

        public void turnOff() {
            System.out.println("Turning off " + brand + " appliance");
       }

        public String getBrand() {
            return brand;
        }

        public double getPowerConsumption() {
            return powerConsumption;
        }
    }

    static class WashingMachine extends Appliance {
        private int drumSize;

        public WashingMachine(String brand, double powerConsumption, int drumSize) {
            super(brand, powerConsumption);
            this.drumSize = drumSize;
        }

        public void washClothes() {
            System.out.println("Washing clothes in a " + getBrand() + " washing machine");
        }

        public int getDrumSize() {
            return drumSize;
        }
    }

    static class Refrigerator extends Appliance {
        private double temperature;

        public Refrigerator(String brand, double powerConsumption, double temperature) {
            super(brand, powerConsumption);
            this.temperature = temperature;
        }

        public void coolItems() {
            System.out.println("Cooling items in a " + getBrand() + " refrigerator at " + temperature + "°C");
        }

        public void setTemperature(double temperature) {
            this.temperature = temperature;
        }

        public double getTemperature() {
            return temperature;
        }
    }

    static class SmartWashingMachine extends WashingMachine {
        private boolean hasWiFi;

        public SmartWashingMachine(String brand, double powerConsumption, int drumSize, boolean hasWiFi) {
            super(brand, powerConsumption, drumSize);
            this.hasWiFi = hasWiFi;
        }

        public void connectToWiFi() {
            if (hasWiFi) {
                System.out.println("Smart Washing Machine connected to WiFi");
            } else {
                System.out.println("This washing machine does not support WiFi");
            }
        }

        public boolean hasWiFi() {
            return hasWiFi;
        }
    }

}

