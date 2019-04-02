#ifndef _NODE_H_
#define _NODE_H_


namespace ai {

class Node
{
    public:
        static const unsigned NullIndex = UINT_MAX;
        Net() : _connected(false) { }
        Net(const std::string &n) : _name( n ) ,_connected(false) { }
        const std::string& name() const { return _name; }

        bool isConnected() const { return _connected; }
        void isConnected(bool c) { _connected = c; }

        unsigned numPins() const {
            return _pins.size();
        }
        void addPin(const std::string &name) {
            _pins.emplace_back(name);
        }
        void addWire(const Point &p1, const Point &p2, unsigned char z, unsigned code = 0) {
            _wires.emplace_back(p1, p2, z, code);
        }
        void addWire(int fx, int fy, int tx, int ty, unsigned char z, unsigned code = 0) {
            _wires.emplace_back(fx, fy, tx, ty, z, code);
        }
        void addVia(const Point &p, unsigned char fz, unsigned char tz, unsigned code = 0) {
            _wires.emplace_back(p, fz, tz, code);
        }
        void addVia(int x, int y, unsigned char fz, unsigned char tz, unsigned code = 0) {
            _wires.emplace_back(x, y, fz, tz, code);
        }
        void addGuide(int lx, int ly, int hx, int hy, unsigned char z);
        void addGuide(const Shape &guide);

        std::vector<Wire>& wires() { return _wires; }
        const std::vector<Wire>& wires() const { return _wires; }

        Guides guides() { return _guides; }
        const Guides guides() const { return _guides; }
        void isConnected();
        void mergeLayerGuidesH(Guides &guides, unsigned char layer);
        void mergeLayerGuidesV(Guides &guides, unsigned char layer);
        void mergeGuides(Guides &guides, char dir);
        void cleanGuides();
        void createGuides();

        unsigned outOfGuideViaCount() const;
        int outOfGuideWireLength() const;
        unsigned totalViaCount() const;
        int totalWireLength() const;
        unsigned offTrackViaCount() const;
        int offTrackWireLength() const;
        int wrongWayWireLength() const;
        void report() const {
            std::cout<<_name<<std::endl;
            unsigned numWires = _wires.size();
            for( unsigned wireIdx = 0; wireIdx < numWires; ++wireIdx )
            {
                const Wire &wire = _wires[wireIdx];
                wire.report();
            }
        }

    private:
};

}

#endif

