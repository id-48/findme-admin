import 'package:find_me_admin/models/imageData/res_imageData.dart';
import 'package:find_me_admin/models/product/add_product/req_add_product.dart';
import 'package:find_me_admin/models/product/get_product/res_get_product.dart';
import 'package:find_me_admin/models/product/update_product/req_update_product.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/add_product_screen.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';
import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:multi_select_flutter/multi_select_flutter.dart';

import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/text_styles.dart';

class AddProductDialog extends StatefulWidget {
  static String tag = '/AddBranchDialog';

  final ProductData? productData;
  final Function()? onUpdate;

  AddProductDialog({this.onUpdate, this.productData});

  @override
  State<AddProductDialog> createState() => _AddroductState();
}

class _AddroductState extends State<AddProductDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController productController = TextEditingController();

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  List<String> colorsApiList = [];
  List<String> designingApiList = [];
  List<String> footRestApiList = [];
  List<String> jackBaseApiList = [];
  List<ImageDatum> imageList = [];

  List<String> selectedColorList = [];
  List<String> selectedDesigningList = [];
  List<String> selectedfootRestApiList = [];
  List<String> selectedjackBaseApiList = [];

  ImageDatum? defaultData;
  bool isLoader = true;

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.productData != null;
    print("isUpdate11 :: ${isUpdate}");
    loaderFalse(true);
    getImageDataApiCall();
    getColorsApiCall();
    getDesigningApiCall();
    getFootRestpiCall();
    getJackBaseApiCall();
    print("isUpdate22 :: ");

    if (isUpdate) {
      print("widget.productData!.colors :: ${widget.productData!.colors}");
      productController.text = widget.productData!.productName.validate();
      selectedColorList = widget.productData!.colors;
      selectedDesigningList = widget.productData!.designing;
      selectedfootRestApiList = widget.productData!.footrest;
      selectedjackBaseApiList = widget.productData!.jackBase;
      setState(() {});
    }
    Future.delayed(Duration(seconds: 2), () async {
      await loaderFalse(false);
    });

    print("isUpdate333 }");
  }

  loaderFalse(bool loader) {
    isLoader = loader;
    print("isUpdate 444 :");

    setState(() {});
  }

  getColorsApiCall() async {
    // await getColors().then((value) {
    //   if (value.status == true) {
    //     // colorsApiList = value.colors;
    //
    //     if (value.colors.length > 0) {
    //       for (int i = 0; i < value.colors.length; i++) {
    //         colorsApiList.add(value.colors[i].colorsName);
    //       }
    //     }
    //
    //     setState(() {});
    //   }
    // });
  }

  getDesigningApiCall() async {
    // await getDesigning().then((value) {
    //   if (value.status == true) {
    //     // designingApiList = value.designing;
    //     if (value.designing.length > 0) {
    //       for (int i = 0; i < value.designing.length; i++) {
    //         designingApiList.add(value.designing[i].designing);
    //       }
    //     }
    //     setState(() {});
    //   }
    // });
  }

  getFootRestpiCall() async {
    await getFootrest().then((value) {
      if (value.status == true) {
        // footRestApiList = value.footRest;
        if (value.footRest.length > 0) {
          for (int i = 0; i < value.footRest.length; i++) {
            footRestApiList.add(value.footRest[i].footRest);
          }
        }
        setState(() {});
      }
    });
  }

  getJackBaseApiCall() async {
    await getJackBase().then((value) {
      if (value.status == true) {
        // jackBaseApiList = value.jackBase;
        if (value.jackBase.length > 0) {
          for (int i = 0; i < value.jackBase.length; i++) {
            jackBaseApiList.add(value.jackBase[i].jackBase);
          }
        }
        setState(() {});
      }
    });
  }

  getImageDataApiCall() async {
    await getImageData().then((value) {
      if (value.status == true) {
        imageList = value.imageData;
        defaultData = imageList[0];
        setState(() {});
      }
    });
  }

  addProductDataApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      print("image :: ${defaultData!.image.toString()}");
      ReqAddProduct productData = await ReqAddProduct(
        productName: productController.text.trim(),
        imageNumber: defaultData!.imageNumber,
        image: defaultData!.image
            .toString()
            .replaceAll("[", "")
            .replaceAll("]", ""),
        colors: selectedColorList,
        designing: selectedDesigningList,
        footrest: selectedfootRestApiList,
        jackBase: selectedjackBaseApiList,
      );

      await addProduct(req: productData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");

          Navigator.pushNamed(context, AddProductScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  updateProductApiCall() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      ReqUpdateProduct updateProductData = ReqUpdateProduct(
        productId: widget.productData!.id,
        productName: productController.text.trim(),
        imageNumber: defaultData!.imageNumber,
        image: defaultData!.image
            .toString()
            .replaceAll("[", "")
            .replaceAll("]", ""),
        colors: selectedColorList,
        designing: selectedDesigningList,
        footrest: selectedfootRestApiList,
        jackBase: selectedjackBaseApiList,
      );

      await updateProduct(req: updateProductData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          Navigator.pushNamed(context, AddProductScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      actionsPadding: EdgeInsets.only(right: 16, bottom: 16),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text("Add Product Details",
              style: boldTextStyle(color: primaryColor, size: 20)),
          IconButton(
            icon: Icon(Icons.close),
            padding: EdgeInsets.zero,
            onPressed: () {
              Navigator.pop(context, false);
            },
          ),
        ],
      ),
      content: Observer(builder: (context) {
        print("colorsApiList ::${colorsApiList.toString()}");
        return SingleChildScrollView(
          child: Stack(
            children: [
              Visibility(
                visible: !appStore.isLoading,
                child: Form(
                  key: _formKey,
                  child: SizedBox(
                    width: ResponsiveWidget.isMediumScreen(context)
                        ? getBodyWidth(context)
                        : (getBodyWidth(context) - 48) * 0.4,
                    child: isLoader
                        ? Column(
                            children: [
                              SizedBox(
                                child: CircularProgressIndicator(),
                                width: 40,
                                height: 40,
                              ),
                            ],
                          )
                        : Column(
                            crossAxisAlignment: CrossAxisAlignment.start,
                            mainAxisSize: MainAxisSize.min,
                            children: [
                              Text("Product Name", style: primaryTextStyle()),
                              SizedBox(height: 8),
                              AppTextField(
                                controller: productController,
                                textFieldType: TextFieldType.NAME,
                                decoration: commonInputDecoration(),
                                textInputAction: TextInputAction.next,
                                errorThisFieldRequired:
                                    "This field is required",
                              ),
                              SizedBox(height: 16),
                              Text("Colors", style: primaryTextStyle()),
                              SizedBox(height: 8),
                              MultiSelectDialogField(
                                searchHint: "Select Colors",
                                decoration: BoxDecoration(
                                  color: Colors.grey.withOpacity(0.15),
                                  borderRadius: BorderRadius.circular(8),
                                ),
                                title: Row(
                                  mainAxisAlignment:
                                      MainAxisAlignment.spaceBetween,
                                  children: [
                                    Text("Select Colors",
                                        style: boldTextStyle(
                                            color: primaryColor, size: 20)),
                                    IconButton(
                                      icon: Icon(Icons.close),
                                      padding: EdgeInsets.zero,
                                      onPressed: () {
                                        Navigator.pop(context, false);
                                      },
                                    ),
                                  ],
                                ),
                                dialogWidth: 500,
                                dialogHeight: 500,
                                items: colorsApiList
                                    .map((String e) => MultiSelectItem(e, e))
                                    .toList(),
                                listType: MultiSelectListType.LIST,
                                initialValue: selectedColorList,
                                onConfirm: (values) {
                                  selectedColorList = values;
                                },
                              ),
                              SizedBox(height: 16),
                              Text("Designing", style: primaryTextStyle()),
                              SizedBox(height: 8),
                              MultiSelectDialogField(
                                searchHint: "Select Designing",
                                decoration: BoxDecoration(
                                  color: Colors.grey.withOpacity(0.15),
                                  borderRadius: BorderRadius.circular(8),
                                ),
                                title: Row(
                                  mainAxisAlignment:
                                      MainAxisAlignment.spaceBetween,
                                  children: [
                                    Text("Select Designing",
                                        style: boldTextStyle(
                                            color: primaryColor, size: 20)),
                                    IconButton(
                                      icon: Icon(Icons.close),
                                      padding: EdgeInsets.zero,
                                      onPressed: () {
                                        Navigator.pop(context, false);
                                      },
                                    ),
                                  ],
                                ),
                                dialogWidth: 500,
                                dialogHeight: 500,
                                items: designingApiList
                                    .map((String e) => MultiSelectItem(e, e))
                                    .toList(),
                                listType: MultiSelectListType.LIST,
                                initialValue: selectedDesigningList,
                                onConfirm: (values) {
                                  selectedDesigningList = values;
                                },
                              ),
                              SizedBox(height: 16),
                              Text("Foot Rest", style: primaryTextStyle()),
                              SizedBox(height: 8),
                              MultiSelectDialogField(
                                searchHint: "Select Foot Rest",
                                decoration: BoxDecoration(
                                  color: Colors.grey.withOpacity(0.15),
                                  borderRadius: BorderRadius.circular(8),
                                ),
                                title: Row(
                                  mainAxisAlignment:
                                      MainAxisAlignment.spaceBetween,
                                  children: [
                                    Text("Select Foot Rest",
                                        style: boldTextStyle(
                                            color: primaryColor, size: 20)),
                                    IconButton(
                                      icon: Icon(Icons.close),
                                      padding: EdgeInsets.zero,
                                      onPressed: () {
                                        Navigator.pop(context, false);
                                      },
                                    ),
                                  ],
                                ),
                                dialogWidth: 500,
                                dialogHeight: 500,
                                items: footRestApiList
                                    .map((String e) => MultiSelectItem(e, e))
                                    .toList(),
                                listType: MultiSelectListType.LIST,
                                initialValue: selectedfootRestApiList,
                                onConfirm: (values) {
                                  selectedfootRestApiList = values;
                                },
                              ),
                              SizedBox(height: 16),
                              Text("Jack and Base", style: primaryTextStyle()),
                              SizedBox(height: 8),
                              MultiSelectDialogField(
                                searchHint: "Select Jack and Base",
                                decoration: BoxDecoration(
                                  color: Colors.grey.withOpacity(0.15),
                                  borderRadius: BorderRadius.circular(8),
                                ),
                                title: Row(
                                  mainAxisAlignment:
                                      MainAxisAlignment.spaceBetween,
                                  children: [
                                    Text("Select Jack and Base",
                                        style: boldTextStyle(
                                            color: primaryColor, size: 20)),
                                    IconButton(
                                      icon: Icon(Icons.close),
                                      padding: EdgeInsets.zero,
                                      onPressed: () {
                                        Navigator.pop(context, false);
                                      },
                                    ),
                                  ],
                                ),
                                dialogWidth: 500,
                                dialogHeight: 500,
                                items: jackBaseApiList
                                    .map((String e) => MultiSelectItem(e, e))
                                    .toList(),
                                listType: MultiSelectListType.LIST,
                                initialValue: selectedjackBaseApiList,
                                onConfirm: (values) {
                                  selectedjackBaseApiList = values;
                                },
                              ),
                              SizedBox(height: 16),
                              Text("Product Image", style: primaryTextStyle()),
                              SizedBox(height: 8),
                              DropdownButtonFormField<ImageDatum>(
                                dropdownColor: Theme.of(context).cardColor,
                                value: defaultData,

                                decoration: commonInputDecoration(),
                                iconSize: 100,
                                items: imageList
                                    .map<DropdownMenuItem<ImageDatum>>((item) {
                                  return DropdownMenuItem(
                                    value: item,
                                    child: Padding(
                                      padding: const EdgeInsets.all(8.0),
                                      child: Row(
                                        mainAxisAlignment:
                                            MainAxisAlignment.spaceBetween,
                                        children: [
                                          ClipRRect(
                                              borderRadius:
                                                  BorderRadius.circular(10),
                                              child: commonCachedNetworkImage(
                                                  "${mBaseUrl + item.image[0]}",
                                                  fit: BoxFit.fill,
                                                  height: 100,
                                                  width: 100)),
                                          Text("${item.imageNumber}",
                                              style: primaryTextStyle()),
                                        ],
                                      ),
                                    ),
                                  );
                                }).toList(),
                                onChanged: (value) {
                                  defaultData = value;
                                  print(
                                      "imageNumber ::: ${defaultData!.imageNumber}");
                                  setState(() {});
                                },
                                // validator: (value) {
                                //   if (defaultData.isEmptyOrNull)
                                //     return "This field is required";
                                //   return null;
                                // },
                              ),
                            ],
                          ),
                  ),
                ),
              ),
              Visibility(visible: appStore.isLoading, child: loaderWidget()),
            ],
          ),
        );
      }),
      actions: <Widget>[
        dialogSecondaryButton("Cancel", () {
          Navigator.pop(context, false);
        }),
        SizedBox(width: 4),
        dialogPrimaryButton(isUpdate ? "Update" : "Add", () {
          isUpdate ? updateProductApiCall() : addProductDataApi();
        }),
      ],
    );
  }
}
