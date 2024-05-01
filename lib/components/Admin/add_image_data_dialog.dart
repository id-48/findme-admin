import 'package:find_me_admin/models/imageData/res_imageData.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/utils/Extensions/colors.dart';
import 'package:find_me_admin/utils/Extensions/text_styles.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/widget/selected_image_viewer.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:image_picker/image_picker.dart';

import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Constants.dart';

class AddImageDataDialog extends StatefulWidget {
  static String tag = '/AddImageDataDialog';
  final ImageDatum? imageData;
  final Function()? onUpdate;

  AddImageDataDialog({this.onUpdate, this.imageData});

  @override
  State<AddImageDataDialog> createState() => _AddImageDataDialogState();
}

class _AddImageDataDialogState extends State<AddImageDataDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  XFile? imageXFile;
  List<XFile> imageXFileList = [];
  List<Uint8List> imageList = [];

  bool isUpdate = false;

  @override
  void initState() {
    super.initState();

    init();
  }

  Future<void> init() async {
    isUpdate = widget.imageData != null;
    if (widget.imageData != null) if (isUpdate) {
      imagesDataAdd();
      setState(() {});
    }
  }

  Future imagesDataAdd() async {
    if (widget.imageData!.image.isNotEmpty &&
        widget.imageData!.image.length != 0) {
      for (int i = 0; i < widget.imageData!.image.length; i++) {
        imageList.add(await imageDataURLtoUint8List(
            mBaseUrl + widget.imageData!.image[i]));
      }

      setState(() {});
    }
  }

  AddImageDataApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      await addImageData(
        context: context,
        image: imageList,
      );
    }
  }

  UpdateImageDataApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      await updateImageData(
        context: context,
        imageDataId: widget.imageData!.id,
        image: imageList,
      );
    }
  }

  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  Future<void> getImage() async {
    imageXFile = await ImagePicker().pickImage(source: ImageSource.gallery);

    if (imageXFile!.path.isNotEmpty) {
      Uint8List image = await imageXFile!.readAsBytes();
      imageList.add(image);
      setState(() {});
    }
  }

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      actionsPadding: EdgeInsets.only(right: 16, bottom: 16),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text(isUpdate ? "Update Image Data" : "Add Image Data",
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
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Text("Add Image", style: primaryTextStyle()),
                        SizedBox(height: 16),
                        SizedBox(
                          width: 120,
                          height: 40,
                          child: ElevatedButton(
                            style: ElevatedButton.styleFrom(
                                shape: RoundedRectangleBorder(
                                    borderRadius: BorderRadius.circular(8.0),
                                    side: BorderSide(color: viewLineColor)),
                                elevation: 0,
                                backgroundColor: Colors.transparent,
                                shadowColor: Colors.transparent),
                            child: Text("Select File",
                                style: boldTextStyle(color: Colors.grey)),
                            onPressed: () {
                              getImage();
                            },
                          ),
                        ),
                        SizedBox(height: 10),
                        SelectedImageViewer(res: imageList, setState: setState),
                        SizedBox(height: 16),
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
          isUpdate ? UpdateImageDataApi() : AddImageDataApi();
        }),
      ],
    );
  }
}
