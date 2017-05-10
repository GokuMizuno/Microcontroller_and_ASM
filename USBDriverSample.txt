/*Sample USB driver for Linux machines
 *Build the driver (.ko file) by running make.
 *Load the driver using insmod.
 *List the loaded modules using lsmod.
 *Unload the driver using rmmod
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

stat int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	struct usb_host_interface *iface_desk;
	struct usb_endpoint_descriptor *endpoint;
	int i;

	iface_desc = interface->cur_altsetting;
	printk(KERN_INFO "USB Pen Drive (%04X:%04X) plugged in\n", id->idVendor, id->idProduct);
	printk(KERN_INFO "Pen i/f #d now probed:  (%04X:%04X)\n", iface_desc->descbInterfaceNumber, id->idVendor, id->idProduct);
	printk(KERN_INFO "ID->bNumEndpoints: %02X\n", iface_desk->desc.bNumEndpoints);
	printk(KERN_INFO "ID->bInterfaceClass: %02X\n", iface_desk->desc.bInterfaceClass);

	for(i=0;i<iface_desk->desc.bNumEndpoints;i++)
	{
		endpoint = &iface_desc->endpoint[i].desc;
		printk(KERN_INFO "ED[%d]->bEndpointAddress: 0x%02X\n", i, endpoint->bEndpointAddress);
        	printk(KERN_INFO "ED[%d]->bmAttributes: 0x%02X\n", i, endpoint->bmAttributes);
        	printk(KERN_INFO "ED[%d]->wMaxPacketSize: 0x%04X (%d)\n",i, endpoint->wMaxPacketSize, endpoint->wMaxPacketSize);
	}
	device = interface_to_usbdev(interface);
	return 0;
}

static void pen_disconnect(struct usb_interface *interface)
{
	printk(KERN_INFO "USB Pen Drive removed\n", interface->cur_altsetting->desc.bInterfaceNumber);
}

static struct usb_device_id pen_table[] = 
{
	{ USB_DEVICE(0xo58f, 0x6387)  },
	{}  /*Entry termination*/
};
MODULE_DEVICE_TABLE (usb, pen_table);

static struct usb_driver pen_table = 
{
	.name = "pen_driver",
	.probe = pen_probe,
	.disconnect = pen_disconnect,
	.id_table = pen_table;
};

static int __init pen_init(void)
{
	return usb_register(&open_driver);
}

static void __exit pen_exit(void)
{
	usb_deregister(&open_driver);
}

module_init(pen_init);
module_exit(pen_exit);
